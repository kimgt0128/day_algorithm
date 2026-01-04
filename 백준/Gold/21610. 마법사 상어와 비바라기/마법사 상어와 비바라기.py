import sys

n, m = map(int, sys.stdin.readline().split())

board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

order = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]

# 방향
direct = [(0, -1), (-1, -1), (-1, 0), (-1, 1), (0, 1), (1, 1), (1, 0), (1, -1)]
# 유효한 좌표 확인
valid_cor = set((r, c) for r in range(n) for c in range(n))

# 초기 구름 생성
cloud = [[n-1, 0], [n-1, 1], [n-2, 0], [n-2, 1]]

for o in order:

    dir, dis = o

    # 구름 이동 및 물복사
    for c in cloud:
        c[0] = (c[0] + direct[dir-1][0] * dis) % n
        c[1] = (c[1] + direct[dir-1][1] * dis) % n

        board[c[0]][c[1]] += 1
        

    # 대각선이 범위 내이고 물양이 0 이상이면 물복사 시전
    for r, c in cloud:
        for (dy, dx) in [(1, 1), (-1, 1), (1, -1), (-1, -1)]:
            ny, nx = (r + dy, c + dx)
            if (ny, nx) in valid_cor and board[ny][nx] > 0:
                board[r][c] += 1

    # 비 구름칸 중 2 이상인 칸에 대하여 새 구름 생성
    cloud_set = set(tuple(c) for c in cloud)

    new_cloud = [[r, c] for r in range(n) for c in range(n) if board[r][c] >= 2 and (r, c) not in cloud_set]

 
    for c in new_cloud:
        board[c[0]][c[1]] -= 2
    
    cloud = new_cloud

print(sum(sum(row) for row in board))
    


    
    
