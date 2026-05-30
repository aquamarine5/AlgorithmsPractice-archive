import java.net.URLDecoder
import java.nio.charset.StandardCharsets
import java.util.Base64

data class CidScResult(
    val cid: String?,
    val sc: String?,
    val source: String,
    val note: String
)

private fun parseByKeys(text: String): Pair<String, String>? {
    val cid = Regex("""(?:^|[?&;,\s])cid=([^&;,\s]+)""", RegexOption.IGNORE_CASE).find(text)?.groupValues?.get(1)
    val sc = Regex("""(?:^|[?&;,\s])sc=([^&;,\s]+)""", RegexOption.IGNORE_CASE).find(text)?.groupValues?.get(1)
    if (cid != null && sc != null) return cid to sc
    return null
}

private fun parseBySeparator(text: String): Pair<String, String>? {
    val trimmed = text.trim()
    val parts = when {
        "|" in trimmed -> trimmed.split('|')
        ":" in trimmed -> trimmed.split(':')
        "," in trimmed -> trimmed.split(',')
        else -> return null
    }
    if (parts.size != 2) return null
    val left = parts[0].trim()
    val right = parts[1].trim()
    if (left.isEmpty() || right.isEmpty()) return null
    return left to right
}

private fun decodeBase64(input: String): String? {
    return runCatching {
        String(Base64.getDecoder().decode(input), StandardCharsets.UTF_8)
    }.getOrNull()
}

private fun decodeHex(input: String): String? {
    if (input.length % 2 != 0 || !input.matches(Regex("^[0-9a-fA-F]+$"))) return null
    return runCatching {
        val bytes = ByteArray(input.length / 2)
        for (i in bytes.indices) {
            bytes[i] = input.substring(i * 2, i * 2 + 2).toInt(16).toByte()
        }
        String(bytes, StandardCharsets.UTF_8)
    }.getOrNull()
}

fun tryDeriveCidSc(clientId: String): CidScResult {
    val candidates = linkedMapOf<String, String>()
    candidates["raw"] = clientId
    candidates["urlDecoded"] = runCatching { URLDecoder.decode(clientId, StandardCharsets.UTF_8) }.getOrDefault(clientId)
    decodeBase64(clientId)?.let { candidates["base64"] = it }
    decodeHex(clientId)?.let { candidates["hex"] = it }

    for ((source, value) in candidates) {
        parseByKeys(value)?.let { (cid, sc) ->
            return CidScResult(cid, sc, source, "Matched cid/sc key-value pattern.")
        }
        parseBySeparator(value)?.let { (cid, sc) ->
            return CidScResult(cid, sc, source, "Matched two-part separator pattern.")
        }
    }

    return CidScResult(
        cid = null,
        sc = null,
        source = "none",
        note = "Unable to reliably derive cid/sc from clientId alone. Additional signing/encryption logic is required."
    )
}

fun main(args: Array<String>) {
    if (args.isEmpty()) {
        println("Usage: kotlin a.kt <clientId>")
        return
    }
    val result = tryDeriveCidSc(args[0])
    println("source=${result.source}")
    println("cid=${result.cid ?: "N/A"}")
    println("sc=${result.sc ?: "N/A"}")
    println("note=${result.note}")
}
