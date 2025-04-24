a = int(input())
b = [0] + [int(x) for x in input().split()]
p = [0 for i in range(a + 1)]
for x in range(1, a + 1):
    p[b[x]] = x
print(p)
r = 0
for i in range(1, a + 1):
    e = b[i]
    if e != i:
        p[b[i]] = p[i]
        r += 1
        tmp = b[i]
        b[i] = b[p[i]]
        b[p[i]] = tmp
print(r)
