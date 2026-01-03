import sys
from itertools import permutations

def solve():
    # 1. 입력 받기
    input = sys.stdin.read().split()
    if not input: return
    n = int(input[0])
    words = input[1:]

    # 2. 등장하는 알파벳 찾기
    unique_chars = sorted(list(set("".join(words))))
    k = len(unique_chars)

    # 3. [핵심] 각 알파벳의 가중치 미리 계산 (루프 밖에서 딱 한 번!)
    # 예: "ABC" -> A는 100, B는 10, C는 1의 가중치를 가짐
    char_weights = []
    for char in unique_chars:
        weight = 0
        for word in words:
            length = len(word)
            for i in range(length):
                if word[i] == char:
                    # 자릿수에 따른 가중치 (10의 거듭제곱)
                    weight += 10 ** (length - i - 1)
        char_weights.append(weight)

    # 4. 브루트포스 탐색 (10개 중 k개를 순서대로 뽑음)
    nums = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    max_ans = 0

    # p는 unique_chars[i]에 배정된 숫자 리스트
    for p in permutations(nums, k):
        current_sum = 0
        # 문자열 변환 없이 숫자 곱셈과 덧셈만 수행 (매우 빠름)
        for i in range(k):
            current_sum += char_weights[i] * p[i]
        
        if current_sum > max_ans:
            max_ans = current_sum

    print(max_ans)

if __name__ == '__main__':
    solve()