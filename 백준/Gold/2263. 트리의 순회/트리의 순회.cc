#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> inorder;
vector<int> postorder;

int find(int value, int start_idx, int end_idx)
{
    for (int i = start_idx; i <= end_idx; ++i)
        if (inorder[i] == value) return i;
}

void construct(int inorder_start, int inorder_end, int postorder_start, int postorder_end)
{
    if (inorder_start > inorder_end || postorder_start > postorder_end) return;
    int root = postorder[postorder_end];

    int root_idx = find(root, inorder_start, inorder_end);

    cout << inorder[root_idx] << ' ';

    construct(inorder_start, root_idx - 1, postorder_start, postorder_start + root_idx - inorder_start - 1);
    construct(root_idx + 1, inorder_end, postorder_start + root_idx - inorder_start, postorder_end - 1);
}

int main()
{
    cin >> N;
    inorder.resize(N);
    postorder.resize(N);

    for (int i = 0; i < N; ++i) cin >> inorder[i];
    for (int i = 0; i < N; ++i) cin >> postorder[i];

    construct(0, N - 1, 0, N - 1);
}