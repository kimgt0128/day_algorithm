import sys

from bisect import bisect_left

n, m = map(int, sys.stdin.readline().split())

dat = list(map(int, sys.stdin.readline().split()))

def check(cur):
    mini = maxi = dat[0]

    cnt = 1

    for d in dat:
        maxi = max(maxi, d)
        mini = min(mini, d)
        if maxi - mini > cur:
            maxi = mini = d
            cnt += 1


    return cnt <= m

max_val = max(dat)
min_val = min(dat)

ans = bisect_left(range(max_val - min_val + 1), True, key=lambda x : check(x))

print(ans)