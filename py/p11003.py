# 1: 101, 110
# 0: 000, 011

# 101: 101101101101 n/3
# 110: 110110110110 n/3
# 000: 000000000000 1
# 011: 011011011011 n/3


def calculate(n: int) -> int:
    return 2 * n if n % 3 == 0 else 2 * (n // 3) + n % 3


i = int(input())
for _ in range(i):
    n = int(input())
    print(calculate(n))
