l = int(input())
count = 0

for x1 in range(1, l + 1):
    for y1 in range(1, l + 1):
        for x2 in range(1, l + 1):
            max_y2 = (l - x1 * x2) // y1 if y1 > 0 else l
            if max_y2 >= 1:
                count += min(l, max_y2)

print(count)
