def solution(s):
    isRight = True
    stack = []
    for i in s:
        if i == '(':
            stack.append(i)
        else:
            if len(stack) == 0:
                return False
            top = stack[len(stack) - 1]
            if (top == '('):
                stack.pop()
            else:
                return False
            

    if stack != []:
        isRight = False

    return isRight