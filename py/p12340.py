h, w = [int(x) for x in input().split(" ")]
ans = 0
for i in range(h):
    c = i % 7
    for j in range(1, w + 1):
        c += 1
        if c == 8:
            c = 1
        if c == 2 or c == 6:
            ans += 1
print(ans)
