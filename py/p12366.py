def cmp(v: tuple) -> int:
    return v[1]


def count(x: int) -> int:
    cu = x
    sumcount = 0
    while x > 0:
        sumcount += x % 10
        x //= 10
    return sumcount


l = []
n = int(input())
m = int(input())
for i in range(n):
    l.append((i + 1, count(i + 1)))
l.sort(key=cmp)
print(l[m - 1][0])
