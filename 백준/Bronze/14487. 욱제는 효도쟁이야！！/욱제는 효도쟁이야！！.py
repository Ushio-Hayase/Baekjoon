input()
arr = list(map(int, input().split()))
max_elem = max(arr)
print(sum(arr)-max_elem)