s = "2025"
a, b = map(int, input().split())
for i in range(0, a):
    s1 = ""
    for j in range(0, b):
        s1 = s1 + s[(i + j) % 4]
    print(s1)
