from collections import deque

def solve_tomato(M, N, grid):
    directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
    queue = deque()
    unripe = 0
    
    for i in range(N):
        for j in range(M):
            if grid[i][j] == 1:
                queue.append((i, j, 0))
            elif grid[i][j] == 0:
                unripe += 1
    
    if unripe == 0:
        return 0
    
    while queue:
        x, y, days = queue.popleft()
        for dx, dy in directions:
            nx, ny = x + dx, y + dy
            if 0 <= nx < N and 0 <= ny < M and grid[nx][ny] == 0:
                grid[nx][ny] = 1
                queue.append((nx, ny, days + 1))
                unripe -= 1
    
    return days if unripe == 0 else -1

# 입력 받기
M, N = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(N)]
print(solve_tomato(M, N, grid))