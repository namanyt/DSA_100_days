#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Evaluate a postfix expression with space-separated tokens. */
int main() {
    char line[4000];
    if (!fgets(line, sizeof(line), stdin)) {
        return 0; /* no input */
    }

    long long stack[2000]; /* value stack */
    int top = -1;

    char *token = strtok(line, " \n\t");
    while (token) {
        if (strlen(token) == 1 && strchr("+-*/", token[0])) {
            long long b = stack[top--];
            long long a = stack[top--];
            long long res = 0;
            switch (token[0]) {
                case '+': res = a + b; break;
                case '-': res = a - b; break;
                case '*': res = a * b; break;
                case '/': res = a / b; break;
            }
            stack[++top] = res; /* push result */
        } else {
            stack[++top] = atoll(token); /* push number */
        }
        token = strtok(NULL, " \n\t");
    }

    if (top >= 0) {
        printf("%lld", stack[top]); /* final result */
    }
    return 0; /* success */
}
