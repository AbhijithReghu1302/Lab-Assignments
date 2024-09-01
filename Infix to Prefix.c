#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x) {
    if (top == MAX - 1) {
        printf("Stack overflow!\n");
    } else {
        stack[++top] = x;
    }
}

char pop() {
    if (top == -1) {
        printf("Stack underflow!\n");
        return -1;
    } else {
        return stack[top--];
    }
}

int precedence(char x) {
    switch (x) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

void reverse(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

void infixToPrefix(char infix[], char prefix[]) {
    int i, j = 0;
    char x;

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (isalnum(infix[i])) {
            prefix[j++] = infix[i];
        } else if (infix[i] == ')') {
            push(infix[i]);
        } else if (infix[i] == '(') {
            while ((x = pop()) != ')') {
                prefix[j++] = x;
            }
        } else {
            while (top != -1 && precedence(stack[top]) > precedence(infix[i])) {
                prefix[j++] = pop();
            }
            push(infix[i]);
        }
    }

        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    reverse(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
