n, m = [int(x) for x in input().split()]

dp = [[[0 for _ in range(200)] for _ in range(200)] for _ in range(200)]
dp[0][0][2] = 1
# i 店 j 花 k 酒
MOD = 1000000007
for i in range(n + 1):
    for j in range(m + 1):
        for k in range(101):
            if j > 0:
                dp[i][j][k] += dp[i][j - 1][k + 1]
            if k % 2 == 0 and i > 0:
                dp[i][j][k] += dp[i - 1][j][k // 2]
print(dp[n][m - 1][1] % MOD)
