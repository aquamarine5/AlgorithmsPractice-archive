s = input()
lp = 0
rp = len(s) - 1
sum_val = 0
while lp < rp:
    while s[lp] != "A" and lp < rp:
        lp += 1
    while s[rp] != "B" and lp < rp:
        rp -= 1
    if lp >= rp:
        break
    sum_val += 2
    lp += 1
    rp -= 1
print(len(s) - sum_val)
