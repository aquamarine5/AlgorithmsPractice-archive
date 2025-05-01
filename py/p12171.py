def hash(a):
    return "".join(sorted(a))


def find(a, lst):
    return hash(a[1:]) in lst or hash(a[:-1]) in lst


with open("words.txt") as f:
    words = f.read().splitlines()
    prefect = [w for w in words if len(w) == 1]
    prefect_hashes = [hash(w) for w in prefect]
    l = 1

    while True:
        new_beautiful = [
            w for w in words if len(w) == l + 1 and find(w, prefect_hashes)
        ]
        if not new_beautiful:
            # 找出长度为l的优美字符串中字典序最小的
            longest_beautiful = sorted(w for w in prefect if len(w) == l)[0]
            print(l)  # 打印最长长度
            print(longest_beautiful)  # 打印字典序最小的最长优美字符串
            break
        else:
            l += 1
            prefect.extend(new_beautiful)
            prefect_hashes.extend(hash(w) for w in new_beautiful)
