#include <stdio.h>
int arr[1000001];
int main(){
    int N, M;
    long long last = 0;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
        last < arr[i] && (last = arr[i]);
    }
    long long temp = 0, result = 0, first = 0, mid;
    while (first <= last){
        mid = (first + last) / 2;
        temp = 0;
        for (int i = 0; i < N; i++)
            arr[i] > mid && (temp += (arr[i] - mid));
        if (temp >= M && result < mid)
            result = mid;
        result < mid ? last = mid-1 : (first = mid+1);
    }
    printf("%lld\n", result);
}