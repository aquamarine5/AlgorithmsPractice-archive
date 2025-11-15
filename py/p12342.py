"""
Author: aquamarine5 && aquamarine5_@outlook.com
Copyright (c) 2025 by @aquamarine5, RC. All Rights Reversed.
lovely lonely, but be a quokka.
"""

n = int(input())
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]
a.sort()
b.sort()
# 12 14 22 31
#  3 19 27 44
# C=A-B
bindex = 0
for i in range(n):
    # print(a[i], b[bindex])
    if a[i] > b[bindex]:
        bindex += 1
# print(bindex)
print(n - bindex)
