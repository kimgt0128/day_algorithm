import sys
from itertools import permutations

n = int(sys.stdin.readline())
words = [sys.stdin.readline().strip() for _ in range(n)]

# 1. 등장하는 알파벳들만 추출
unique_chars = list(set("".join(words)))
k = len(unique_chars)

# 2. [핵심] 각 알파벳의 전체 가중치를 미리 계산
# 예: {'A': 101, 'B': 110, 'C': 11}
char_weights = []
for char in unique_chars:
    weight = 0
    for w in words:
        # 단어 안에서 해당 문자가 나타나는 모든 위치의 가중치를 더함
        for i, c in enumerate(w[::-1]):
            if c == char:
                weight += (10 ** i)
    char_weights.append(weight)

# 3. 브루트포스 탐색 시작
nums = list(range(10))
max_ans = 0

# 이제 반복문 안에는 문자열 연산이 전혀 없습니다.
for p in permutations(nums, k):
    current_sum = 0
    for i in range(k):
        # (알파벳의 가중치) * (배정된 숫자) 를 바로 더함
        current_sum += char_weights[i] * p[i]
    
    if current_sum > max_ans:
        max_ans = current_sum

print(max_ans)