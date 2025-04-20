CHARACTER = "Q"
w, h, v = [int(i) for i in input().split(" ")]

for i in range(h):
    print(CHARACTER * w)
for i in range(w):
    print(CHARACTER * (v + w))
