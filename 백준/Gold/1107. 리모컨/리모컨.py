import sys
from itertools import product

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

error = set(sys.stdin.readline().split()) if m > 0 else set()

remain = [str(i) for i in range(10) if str(i) not in error]

ans = abs(n - 100)

# improt from 차이
for length in range(1, 7):
    for p in product(remain, repeat=length):
        s_cur = "".join(p) # 000123

        cur = int(s_cur)

        ans = min(ans, len(str(cur)) + abs(cur - n))

print(ans)

        


