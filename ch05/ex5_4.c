/*
 * 실습4: 스택을 이용한 후위 표기법 수식 연산
 *
 * 알고리즘:
 *  1) 피연산자를 만나면 스택에 push
 *  2) 연산자를 만나면 스택에서 피연산자 2개를 pop하여 연산 후 결과를 push
 *  3) 수식이 끝나면 마지막으로 스택을 pop하여 결과 출력
 *
 * 예) 후위 표기식 "35*62/-"
 *     -> 3*5=15, 6/2=3, 15-3=12
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 100

typedef int element;
element stack[STACK_SIZE];
int top = -1;

void push(element item) {
    if (top == STACK_SIZE - 1) {
        printf("Stack is FULL!\n");
        return;
    }
    stack[++top] = item;
}

element pop() {
    if (top == -1) {
        printf("Stack is Empty!\n");
        return 0;
    }
    return stack[top--];
}

// 후위 표기법 수식 연산 함수
int evalPostfix(char* exp) {
    int i, n;
    element opr1, opr2, result;
    char symbol;
    n = strlen(exp);
    top = -1;   // 스택 초기화

    for (i = 0; i < n; i++) {
        symbol = exp[i];

        if (symbol != '+' && symbol != '-' &&
            symbol != '*' && symbol != '/') {
            // 피연산자: 숫자 문자를 정수로 변환하여 스택에 push
            push(symbol - '0');
        }
        else {
            // 연산자: 스택에서 피연산자 2개를 꺼내 연산
            opr2 = pop();   // 나중에 넣은 값 (오른쪽 피연산자)
            opr1 = pop();   // 먼저 넣은 값  (왼쪽 피연산자)

            switch (symbol) {
                case '+': result = opr1 + opr2; break;
                case '-': result = opr1 - opr2; break;
                case '*': result = opr1 * opr2; break;
                case '/': result = opr1 / opr2; break;
                default:  result = 0; break;
            }
            // 연산 결과를 다시 스택에 push
            push(result);
        }
    }
    // 수식 끝: 스택에 남은 최종 결과값 반환
    return pop();
}

int main(void) {
    char exp[200];
    int result;

    printf("후위 표기식을 입력하세요 (예: 35*62/-): ");
    scanf("%s", exp);

    printf("\n후위 표기식 : %s\n", exp);
    result = evalPostfix(exp);
    printf("연산 결과 => %d\n", result);

    getchar(); getchar();
    return 0;
}
