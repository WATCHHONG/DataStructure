/*
 * 실습3: 스택을 이용한 수식의 괄호쌍 검사
 * - 왼쪽 괄호를 만나면 스택에 push
 * - 오른쪽 괄호를 만나면 스택을 pop하여 같은 종류인지 확인
 * - 수식이 끝났을 때 스택이 공백이면 올바른 괄호 사용
 */
#include <stdio.h>
#include <string.h>

#define STACK_SIZE 100

typedef char element;
element stack[STACK_SIZE];
int top = -1;

int isStackEmpty() {
    return (top == -1);
}

void push(element item) {
    if (top == STACK_SIZE - 1) {
        printf("Stack is FULL!\n");
        return;
    }
    stack[++top] = item;
}

element pop() {
    if (isStackEmpty()) {
        return '\0';
    }
    return stack[top--];
}

// 괄호 쌍 검사 함수
// 반환값: 1 = 올바른 괄호, 0 = 잘못된 괄호
int testPair(char* exp) {
    char symbol, open_pair;
    int i, n;
    n = strlen(exp);
    top = -1;   // 스택 초기화

    for (i = 0; i < n; i++) {
        symbol = exp[i];

        if (symbol == '(' || symbol == '[' || symbol == '{') {
            // 왼쪽 괄호 -> 스택에 push
            push(symbol);
        }
        else if (symbol == ')') {
            open_pair = pop();
            if (open_pair != '(') return 0;   // 짝이 맞지 않음
        }
        else if (symbol == ']') {
            open_pair = pop();
            if (open_pair != '[') return 0;
        }
        else if (symbol == '}') {
            open_pair = pop();
            if (open_pair != '{') return 0;
        }
        // 괄호가 아닌 문자는 무시
    }

    // 수식 끝: 스택이 공백이면 올바른 괄호
    if (isStackEmpty()) return 1;
    else return 0;
}

int main(void) {
    char exp[200];
    printf("수식을 입력하세요: ");
    scanf("%s", exp);
    printf("\n%s\n", exp);

    if (testPair(exp)) {
        printf("\n수식의 괄호가 맞게 사용되었습니다!\n");
    }
    else {
        printf("\n수식의 괄호가 틀리게 사용되었습니다!\n");
    }

    getchar(); getchar();
    return 0;
}
