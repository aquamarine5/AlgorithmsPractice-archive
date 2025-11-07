from datetime import datetime, timedelta

stt = datetime(1970, 1, 1)


def solve(dt: str, x: int) -> str:
    parsed = datetime.strptime(dt, "%Y-%m-%d %H:%M:%S")
    tot = (parsed - stt).total_seconds()
    return (stt + timedelta(seconds=(tot - tot % (x * 60)))).strftime(
        "%Y-%m-%d %H:%M:%S"
    )


i = int(input())
for _ in range(i):
    dt1, dt2, x = input().split(" ")
    print(solve(f"{dt1} {dt2}", int(x)))
