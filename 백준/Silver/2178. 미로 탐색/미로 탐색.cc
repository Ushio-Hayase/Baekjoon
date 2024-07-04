#include <stdio.h>
#include <vector>
#include <queue>
#include <deque>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

int N, M;                       
int maze[101][101];             
int visited[101][101];          
int dist[101][101];             

int x_dir[4] = { -1, 1, 0, 0 }; 
int y_dir[4] = { 0, 0, -1, 1 }; 

queue<pair<int, int> > q;       

void bfs(int start_x, int start_y) {

    visited[start_x][start_y] = 1;         
    q.push(make_pair(start_x, start_y));   
    dist[start_x][start_y]++;              

    while (!q.empty()) {

   
        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for (int i = 0; i < 4; ++i) {

            int x_new = x + x_dir[i];
            int y_new = y + y_dir[i];

            if ((0 <= x_new && x_new < N) && (0 <= y_new && y_new < M)
                && !visited[x_new][y_new] && maze[x_new][y_new] == 1) {

                visited[x_new][y_new] = 1;              
                q.push(make_pair(x_new, y_new));        
                dist[x_new][y_new] = dist[x][y] + 1;    
            }
        }
    }
}


int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++i) {
        string j;
        cin >> j;
        for (int k = 0; k < M; ++k) {   
            maze[i][k] = j[k] - '0';    
        }
    }

    bfs(0, 0);                          

    printf("%d", dist[N - 1][M - 1]);
}
