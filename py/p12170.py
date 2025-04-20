x = 1
hp = 2025
while hp > 0:
    hp -= 5
    if x % 2 == 0:
        hp -= 2
    else:
        hp -= 15
    if x % 3 == 0:
        hp -= 7
    elif x % 3 == 1:
        hp -= 2
    else:
        hp -= 10
    x += 1
print(x - 1)
