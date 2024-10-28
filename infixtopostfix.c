#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

int is_empty() {
    return top == -1;
}

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        exit(1);
    }
    stack[++top] = item;
}

char pop() {
    if (is_empty()) {
        printf("Stack underflow\n");
        exit(1);
    }
    return stack[top--];
}

char peek() {
    if (is_empty()) {
        return '\0';
    }
    return stack[top];
}

int precedence(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

void infix_to_postfix(const char* infix, char* postfix) {
    int i = 0, j = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!is_empty() && peek() != '(') {
                postfix[j++] = pop();
            }
            if (!is_empty()) {
                pop();
            }
        } else {
            while (!is_empty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }
            push(ch);
        }
        i++;
    }

    while (!is_empty()) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter a valid parenthesized infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}
