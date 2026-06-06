#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

// STACK MODULE
int stack[MAX];
int top = -1;
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = x;
    }
}
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    } else {
        return stack[top--];
    }
}
int peek() {
    return stack[top];
}
int isEmpty() {
    return top == -1;
}

// OPERATOR MODULE
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

// CONVERSION MODULE (Infix ? Postfix)
void infixToPostfix(char infix[], char postfix[]) {
    int i = 0, j = 0;
    char ch;
    while (infix[i] != '\0') {
        ch = infix[i];
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }else if (ch == '(') {
            push(ch);
        }else if (ch == ')') {
            while (peek() != '(') {
                postfix[j++] = pop();
            }pop();
        }else if (isOperator(ch)) {
            while (!isEmpty() && precedence(peek()) >= precedence(ch)) {
                postfix[j++] = pop();
            }push(ch);
        }i++;
    }while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}

// EVALUATION MODULE (Postfix)
int evaluatePostfix(char postfix[]) {
    int i = 0;
    char ch;
    int op1, op2;
    while (postfix[i] != '\0') {
        ch = postfix[i];
        if (isdigit(ch)) {
            push(ch - '0');
        }
        else if (isOperator(ch)) {
            op2 = pop();
            op1 = pop();
            switch (ch) {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
        i++;
    }
    return pop();
}

// MAIN (Input + Output)
int main() {
    char infix[100], postfix[100];
    int result;
    printf("----- STACK BASED CALCULATOR -----\n");
    printf("Enter Infix Expression: ");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);
    // Reset stack before evaluation
    top = -1;
    result = evaluatePostfix(postfix);
    printf("Result = %d\n", result);
    return 0;
}
