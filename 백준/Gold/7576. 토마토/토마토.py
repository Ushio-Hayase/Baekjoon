import sys
from collections import deque
import math

def bfs(M, N, levels, start_points):
    # directions: right, left, down, up (x, y)
    moveX = [1, -1, 0, 0]
    moveY = [0, 0, 1, -1]
    
    q = deque()
    # 시작점 초기화: (x, y, current_level)
    for sx, sy in start_points:
        q.append((sx, sy, 0))
    
    while q:
        x, y, current_level = q.popleft()
        for dx, dy in zip(moveX, moveY):
            newX, newY = x + dx, y + dy
            # 범위 체크 및 조건 체크: levels[newY][newX]가 양수이고(즉, 방문 전),
            # 새로운 level(current_level+1)이 기존 값보다 작으면 업데이트
            if 0 <= newX < M and 0 <= newY < N:
                if levels[newY][newX] > 0 and current_level + 1 < levels[newY][newX]:
                    levels[newY][newX] = current_level + 1
                    q.append((newX, newY, current_level + 1))

def main():
    input = sys.stdin.readline
    # M: 가로 칸 수, N: 세로 칸 수
    M, N = map(int, input().split())
    
    levels = [[0] * M for _ in range(N)]
    start_points = []
    
    for i in range(N):
        row = list(map(int, input().split()))
        for j in range(M):
            x = row[j]
            if x == 1:
                start_points.append((j, i))
                levels[i][j] = 0
            elif x == 0:
                # 아직 익지 않은 토마토: 최대값으로 초기화 (도달 불가능하면 그대로 남음)
                levels[i][j] = math.inf
            else:
                # 토마토가 없는 칸: -1로 표기
                levels[i][j] = -1
    
    bfs(M, N, levels, start_points)
    
    result = 0
    for i in range(N):
        for j in range(M):
            tmp = levels[i][j]
            # 만약 익지 않은 토마토(도달할 수 없는 경우)가 있다면 -1 출력 후 종료
            if tmp == math.inf:
                print(-1)
                return
            result = max(result, tmp)
    
    print(result)

if __name__ == "__main__":
    main()
