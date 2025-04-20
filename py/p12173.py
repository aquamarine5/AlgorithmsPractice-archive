def hash(a):
    return sorted(a)


ss = input()
r = 0
i = 0
while i < (len(ss) - 3):
    if hash(ss[i : i + 3]) == ["b", "l", "q"]:
        i += 2
        r += 1
    i += 1
print(r)
