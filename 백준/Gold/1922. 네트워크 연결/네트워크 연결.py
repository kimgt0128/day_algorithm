import sys

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

def find(x):
    if par[x] == x :
        return x
    else:
        par[x] = find(par[x])
        return par[x]
   

def union(a, b):
    a = find(a)
    b = find(b)
    if a < b :
        par[b] = a
    else:
        par[a] = b

def kruskal():
    ret = 0
    cnt = 0

    for c, u, v in edges:
        if find(u) == find(v):
            continue
        if cnt == n - 1:
            break

        union(u, v)
        ret += c
        cnt += 1

    return ret


n = int(input())
m = int(input())
edges = []
mst = 0
par = [i for i in range(n+1)]

for _ in range(m):
    a, b, c = map(int, input().split())
    edges.append((c, a, b))

edges.sort()

print(kruskal())