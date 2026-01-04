import sys

n = int(sys.stdin.readline())

items = [tuple(map(int, sys.stdin.readline().split())) for _ in range(n)]

items.sort(key=lambda x : x[0])

max_h, idx = max((item[1], idx) for idx, item in enumerate(items))


pre = (0, 0)
total = 0
for cur in items[:idx+1]:

    cur_pos, cur_hei = cur
    pre_pos, pre_hei = pre
    

    if cur_hei >= pre_hei:
        total += pre_hei * (cur_pos - pre_pos)
        pre = cur

pre = (0, 0)
for cur in items[:idx-1:-1]:

    cur_pos, cur_hei = cur
    pre_pos, pre_hei = pre

    if cur_hei >= pre_hei:
        total += pre_hei * (pre_pos - cur_pos)
        pre = cur

print(total + max_h)

    



    