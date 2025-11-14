s = 0
for i in range(1, 5000000):
    x = i * 10 + 45
    if str(x) == str(x)[0] * len(str(x)):
        print(x)
        s += x
print(s)
