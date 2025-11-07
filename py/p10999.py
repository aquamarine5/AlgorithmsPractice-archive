def toQuaternary(n):
    if n == 0:
        return 0
    digits = []
    while n:
        digits.append(n % 4)
        n //= 4
    return sum(digits)


def toBinary(n):
    if n == 0:
        return 0
    digits = []
    while n:
        digits.append(n % 2)
        n //= 2
    return sum(digits)


def isPass(i):
    return toQuaternary(i) == toBinary(i)


result = 0
for i in range(1, 2025):
    result += 1 if isPass(i) else 0
print(result)
