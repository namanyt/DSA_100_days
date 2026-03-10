#include <stdio.h>
#include <ctype.h>
#include <string.h>

/* Return operator precedence. */
static int prec(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

/* Convert infix expression to postfix (space-separated). */
int main() {
    int n; /* length (unused but read as per input format) */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }
    getchar(); /* consume newline */

    char expr[2000];
    if (!fgets(expr, sizeof(expr), stdin)) {
        return 0; /* no expression */
    }

    char stack[2000]; /* operator stack */
    int top = -1;
    int first = 1; /* spacing flag */

    for (int i = 0; expr[i]; i++) {
        char c = expr[i];
        if (c == ' ' || c == '\n' || c == '\t') {
            continue; /* skip whitespace */
        }
        if (isalnum((unsigned char)c)) {
            if (!first) {
                printf(" ");
            }
            printf("%c", c); /* operand */
            first = 0;
        } else if (c == '(') {
            stack[++top] = c; /* push '(' */
        } else if (c == ')') {
            while (top >= 0 && stack[top] != '(') {
                if (!first) {
                    printf(" ");
                }
                printf("%c", stack[top--]); /* pop operators */
                first = 0;
            }
            if (top >= 0 && stack[top] == '(') {
                top--; /* discard '(' */
            }
        } else {
            while (top >= 0 && prec(stack[top]) >= prec(c)) {
                if (!first) {
                    printf(" ");
                }
                printf("%c", stack[top--]); /* pop higher/equal precedence */
                first = 0;
            }
            stack[++top] = c; /* push current operator */
        }
    }

    while (top >= 0) {
        if (!first) {
            printf(" ");
        }
        printf("%c", stack[top--]); /* pop remaining operators */
        first = 0;
    }
    return 0; /* success */
}
