#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int numSquares(int n) {
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        dp[i] = INT_MAX;
        for (int j = 1; j * j <= i; j++) {
            if (dp[i - j * j] + 1 < dp[i]) {
                dp[i] = dp[i - j * j] + 1;
            }
        }
    }

    int result = dp[n];
    free(dp);
    return result;
}
int main() {
    int n = 13;
    int result = numSquares(n);
    printf("The least number of perfect squares for %d is %d\n", n, result);
    return 0;
}
