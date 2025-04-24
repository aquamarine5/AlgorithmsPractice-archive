a = int(input())
b = [0] + [int(x) for x in input().split()]
ans = 1
for i in range(1, a):
    for s in range(1, i + 1):
        c = 1
        for j in range(s + i, a + 1, i):
            if b[j] > b[j - i]:
                c += 1
                ans = max(ans, c)
            else:
                c = 1
print(ans)
