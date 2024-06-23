// BaekJoon.cpp : 애플리케이션의 진입점을 정의합니다.
//
#include <stdio.h>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;
int arr[101][101];
int visited[101];
int depth[101];
int result[101];
int N, M;
queue <int> q;
void BFS(int x)
{
	q.push(x);
	visited[x] = 1;
	while (!q.empty())
	{
		int cur_x;
		cur_x = q.front();
		q.pop();
		for (int i = 1; i <= N; i++)
		{
			if (visited[i] == 0 && arr[cur_x][i] == 1)
			{
				visited[i] = 1;
				q.push(i);
				depth[i] = depth[cur_x] + 1;
			}
		}
	}
}

int main()
{

	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int one, two;
		scanf("%d %d", &one, &two);

		arr[one][two] = 1; arr[two][one] = 1;
	}

	for (int i = 1; i <= N; i++)
	{

		BFS(i);
		for (int j = 1; j <= N; j++)
		{
			result[i] += depth[j];
		}
		memset(visited, 0, sizeof(visited));
		memset(depth, 0, sizeof(depth));
	}
	int min = 999999;
	int min_person;
	for (int i = 1; i <= N; i++)
	{
		if (min > result[i])
		{
			min = result[i];
			min_person = i;
		}
	}

	printf("%d", min_person);
}
