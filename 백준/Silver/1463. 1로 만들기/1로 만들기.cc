#include <stdio.h>


int main() {
    int N;
    scanf("%d", &N);

    int memo[10000000] = {0,};

    memo[1] = 0;
    memo[2] = 1;
    memo[3] = 1;
    memo[4] = 2;
    memo[5] = 3;
    memo[6] = 2;

    int i = 7;

    while(i <= N) {
        int num = i;
        int count = 999999;
    
        if(num % 3 == 0) {
            if(memo[num - 1] <= memo[num/3]) {
                count = memo[num-1] +1;
            } 
            if( memo[num - 2] + 1 <= memo[num/3]) {
                count = memo[num -2] + 2 < count ? memo[num -2] + 2 : count;
            }
            count = memo[num/3] + 1 < count ? memo[num/3] + 1  : count;
            
        }
        if (num % 2 == 0) {
            if(memo[num - 1] <= memo[num/2]) {
                count = memo[num-1] +1 < count ? memo[num-1] +1 : count;
            }
            count = memo[num / 2] + 1 < count ? memo[num / 2] + 1 : count;
        }
        count = memo[num-1] + 1 < count ? memo[num-1] + 1 : count;

        memo[i] = count;
        i++;
    }

    printf("%d",memo[N]);
}
