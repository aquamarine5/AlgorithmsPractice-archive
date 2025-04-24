def hash(a):
    return "".join(sorted(a))


def find(a, lst):
    return hash(a[1:]) in lst or hash(a[:-1]) in lst


with open("words.txt") as f:
    words = f.read().splitlines()
    prefect = [w for w in words if len(w) == 1]
    prefectSort = prefect.copy()
    l = 1
    while True:
        w = [w for w in words if len(w) == l + 1 and find(w, prefectSort)]
        if len(w) == 0:
            print(l)
            break
        else:
            l += 1
            prefect.extend(w)
            prefectSort = [hash(w) for w in w]
            print("p", prefectSort)
            print(l, w)
