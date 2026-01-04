import sys
import heapq

n = int(sys.stdin.readline())

p = [0, 0] + list(map(int, sys.stdin.readline().split()))
a = [0] + list(map(int, sys.stdin.readline().split()))

# 전처리
graph = [[] for _ in range(n+1)]

# 부모 - 자식 연결
for child, parent in enumerate(p):
    graph[parent].append(child)

pq = []

heapq.heappush(pq, (-a[1], 1))
total = 0
for _ in range(n):

    val, node = heapq.heappop(pq)
    total += (-val)
    print(total)

    for nxt in graph[node]:
        heapq.heappush(pq, (-a[nxt], nxt))
