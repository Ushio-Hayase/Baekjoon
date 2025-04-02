#include <stdio.h>
#define INF 987654321

int arr[105][105];

int main(){
    int n,m;
    int a,b,c;

    scanf("%d",&n);
    scanf("%d",&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            arr[i][j] = INF;

    for(int i=1;i<=n;i++)
        arr[i][i] = 0;

    for(int i=0;i<m;i++){
        scanf("%d %d %d",&a,&b,&c);

        if(arr[a][b]>c)
            arr[a][b] = c;
    }

    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(arr[i][j]>arr[i][k]+arr[k][j])
                    arr[i][j] = arr[i][k]+arr[k][j];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            if(arr[i][j]==INF) printf("0 ");
            else printf("%d ",arr[i][j]);
        printf("\n");
    }
}