#include <stdio.h>

/* Compute the nth Fibonacci number using recursion. */
static long long fib(int n) {
    if (n <= 1) {
        return n; /* base cases: fib(0)=0, fib(1)=1 */
    }
    return fib(n - 1) + fib(n - 2); /* recursive relation */
}

int main() {
    int n; /* input position */
    if (scanf("%d", &n) != 1) {
        return 0; /* no valid input */
    }

    printf("%lld", fib(n)); /* output result */
    return 0; /* success */
}
