import sys
from itertools import product
sys.setrecursionlimit(10**8)
n, m = map(int, sys.stdin.readline().split())

nums = list(map(int, sys.stdin.readline().split())) if m > 0 else [] #m>0인 경우에만 num 리스트가 존재!

mask = 0
for num in nums:
    mask |= (1 << num)
    
 
def back_tracking(depth, cur):
    if depth == n:
        # 현재 cur의 각 요소하나하나가 num과 cur에 모두 있는 경우

        if (mask & cur == mask):
            return 1
        return 0
    
    res = 0
    for i in range(10):
        res += back_tracking(depth + 1, cur | (1 << i))
    return res


ans = back_tracking(0, 0)

print(ans)