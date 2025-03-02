n, m, k = [int(x) for x in input().split()]
a = [[int(v) for v in input().split()] for _ in range(n)]
ppl = [[0] * (m + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    for j in range(1, m + 1):
        ppl[i][j] = ppl[i - 1][j] + ppl[i][j - 1] - ppl[i - 1][j - 1] + a[i - 1][j - 1]

ans = 0
for x1 in range(1, n + 1):
    for y1 in range(1, m + 1):
        for x2 in range(x1, n + 1):
            for y2 in range(y1, m + 1):
                s = (
                    ppl[x2][y2]
                    - ppl[x1 - 1][y2]
                    - ppl[x2][y1 - 1]
                    + ppl[x1 - 1][y1 - 1]
                )
                if s <= k:
                    ans += 1

print(ans)
