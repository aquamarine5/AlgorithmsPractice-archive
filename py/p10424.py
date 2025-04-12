n = int(input())
count = 0


def is_good(i: int) -> int:

    k = 1
    num = i
    while num > 0:
        if k % 2 == 0 and (num % 10) % 2 == 1:
            return 0
        if k % 2 == 1 and (num % 10) % 2 == 0:
            return 0
        num //= 10
        k += 1
    return 1


for i in range(1, n + 1):
    count += is_good(i)
print(count)
