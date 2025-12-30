import sys

from itertools import combinations

n, m = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

# 특정 좌표만 추출
house = [(r, c) for r, row in enumerate(board) for c, val in enumerate(row) if val == 1]
chicken = [(r, c) for r, row in enumerate(board) for c, val in enumerate(row) if val == 2]

ans = sys.maxsize

for comb in combinations(chicken, m):
    # 각 집의 치킨 거리 구하기
    chicken_dist = sum(min(abs(h[0] - c[0]) + abs(h[1] - c[1]) for c in comb) for h in house)
    #chicken_dist = sum(min(abs(h[0] - c[0]) + abs(h[1] - c[1]) for h in house for c in comb)

    ans = min(ans, chicken_dist)

print(ans)

