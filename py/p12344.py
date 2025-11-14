import queue

n, k = [int(x) for x in input().split()]
vl = [int(x) for x in input().split()]
mp = [[] for _ in range(n + 1)]

for i in range(n - 1):
    a, b = [int(x) for x in input().split()]
    mp[a].append(b)
    mp[b].append(a)
pd = queue.Queue()
result = set([])
ans = 0
pd.put([1, 0])
while pd.empty() == False:
    p = pd.get()
    # print(p)
    result.add(p[0])
    if p[0] in result:
        for i in mp[p[0]]:
            if p[1] + 1 <= k * 2:
                pd.put([i, p[1] + 1])
for i in result:
    ans += vl[i - 1]
print(ans)
