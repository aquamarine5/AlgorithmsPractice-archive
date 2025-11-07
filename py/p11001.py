def main():
    n, m = [int(x) for x in input().split()]
    grd = [[int(x) for x in input().split()] for _ in range(n)]

    # n=3 m=3
    # 1 2
    # 2 3
    # 3 2
    result = 0

    for i in range(n):
        for j in range(m):
            for k in range(1, min(n - i, m - j)):
                if grd[i][j] == grd[i + k][j + k]:
                    result += 1

    for i in range(n):
        for j in range(m):
            for k in range(1, min(n - i, j + 1)):
                if grd[i][j] == grd[i + k][j - k]:
                    result += 1
    print(result * 2)


if __name__ == "__main__":
    main()
