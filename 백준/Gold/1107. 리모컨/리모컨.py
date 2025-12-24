import sys

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

broken = set(sys.stdin.readline().split()) if m > 0 else set()

ans = abs(n - 100)

for channel in range(1000001):
    cur = str(channel)

    for char in cur:
        if char in broken:
            break
    else:
        ans = min(ans, len(cur) + abs(channel - n))

print(ans)
