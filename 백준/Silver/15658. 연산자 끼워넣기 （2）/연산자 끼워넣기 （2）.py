import sys
sys.setrecursionlimit(10**8)

n = int(sys.stdin.readline())

num = list(map(int, sys.stdin.readline().split()))

cnt = list(map(int, sys.stdin.readline().split()))

pick = []
maxi = -sys.maxsize
mini = sys.maxsize


def get_combination(depth):
    global maxi, mini

    if depth == n-1:
        res = num[0]
        for i in range(0, n-1):
            if pick[i] == 0:
                res += num[i+1]
            elif pick[i] == 1:
                res -= num[i+1]
            elif pick[i] == 2:
                res *= num[i+1]
            else:
                res = int(res /  num[i+1])

        maxi = max(maxi, res)
        mini = min(mini, res)
        return
        


    for idx, c in enumerate(cnt):
        if c > 0:
            cnt[idx] -= 1
            pick.append(idx)
            
            get_combination(depth + 1)

            pick.pop()
            cnt[idx] += 1


get_combination(0)

print(maxi)
print(mini)