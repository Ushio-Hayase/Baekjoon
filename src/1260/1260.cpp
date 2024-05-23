#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct LinkedList {
    vector<LinkedList*> link;
    bool visit = false;
    int content;
    LinkedList() = default;
    LinkedList(int data) : content(data), link(0){};

    bool operator<(const LinkedList& obj) const {
        return content < obj.content;
    }
};

void DFS(vector<int>& result, LinkedList* list);
bool compare(LinkedList lhs, LinkedList rhs);
void BFS(vector<int>& result, LinkedList* list);

int main() {
    int N, M, V;
    scanf("%d %d %d", &N, &M, &V);

    vector<LinkedList> node(N);

    for(int i = 0; i < N; i++) {
        node[i] = LinkedList(i);
    }

    for(int i = 0; i < M; i++) {
        int first, second;
        scanf("%d %d", &first, &second);
        node[first - 1].link.push_back(&node[second - 1]);
        node[second - 1].link.push_back(&node[first - 1]);
    }

    vector<int> dfs(0);
    vector<int> bfs(0);

    BFS(bfs, &node[V-1]);

    for(int i = 0; i < node.size(); i++) node[i].visit=false;

    DFS(dfs, &node[V-1]);

    for(auto i : dfs) printf("%d ", i + 1);
    printf("\n");
    for(auto i : bfs) printf("%d ", i + 1);
}

void DFS(vector<int>& result, LinkedList* list) {
    if(!list->visit) result.push_back(list->content);
    
    sort(list->link.begin(), list->link.end());
    list->visit = true;
    

    for(auto i : list->link) {
        if(!i->visit) DFS(result, i);
    }
}

void BFS(vector<int>& result, LinkedList* list) {
    if(!list->visit) result.push_back(list->content);
    list->visit = true;
    queue<LinkedList*> q;
    sort(list->link.begin(), list->link.end());
    for(auto i : list->link) {
        q.push(i);
    }
    while(q.size() != 0) {
        LinkedList* ptr = q.front();
        q.pop();
        sort(ptr->link.begin(), ptr->link.end());
        
        if(!ptr->visit) result.push_back(ptr->content);
        ptr->visit = true;

        for(auto i : ptr->link) {
            if(!i->visit) q.push(i);
        }
    }

}
