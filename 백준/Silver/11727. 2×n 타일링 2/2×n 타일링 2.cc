#include <stdio.h>
int dp[1001];

int main() {
    
    int N;
    scanf("%d", &N);
    
    dp[1] = 1; dp[2] = 3;
    for (int i=3; i<=N; i++)
    	dp[i] = (dp[i-1] + 2*dp[i-2])%10007;
    printf("%d", dp[N]);
    return 0;
}