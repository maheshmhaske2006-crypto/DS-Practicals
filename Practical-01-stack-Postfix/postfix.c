
#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int value) {
    stack[++top] = value;
}

int pop() {
    return stack[top--];
}

int main() {
    char exp[MAX];
    int i, a, b;

    printf("Enter postfix expression: ");
    scanf("%99s", exp);

    for (i = 0; exp[i] != '\0'; i++) {
        if (isdigit((unsigned char)exp[i])) {
            push(exp[i] - '0');
        } else {
            b = pop();
            a = pop();

            switch (exp[i]) {
                case '+': push(a + b); break;
                case '-': push(a - b); break;
                case '*': push(a * b); break;
                case '/':
                    if (b == 0) {
                        printf("Division by zero error\n");
                        return 1;
                    }
                    push(a / b);
                    break;
                default:
                    printf("Invalid operator\n");
                    return 1;
            }
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}