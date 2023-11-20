//12_트리 도전1:1967
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node 
{
    int idx, cnt;

    Node(int i, int c) : idx(i), cnt(c) {}
};

vector<vector<Node>> list;
vector<bool> visited;
int n;
int maxWeight = 0;
int maxIdx = 0;

void dfs(int idx, int cnt) 
{
    if (maxWeight < cnt) 
    {
        maxWeight = cnt;
        maxIdx = idx;
    }

    for (const Node& a : list[idx]) 
    {
        if (!visited[a.idx]) 
        {
            visited[a.idx] = true;
            dfs(a.idx, cnt + a.cnt);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    list.resize(n + 1);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; i++) 
    {
        int parent, child, weight;
        cin >> parent >> child >> weight;
        list[parent].emplace_back(Node(child, weight));
        list[child].emplace_back(Node(parent, weight));
    }

    visited[1] = true;
    dfs(1, 0);

    fill(visited.begin(), visited.end(), false);
    visited[maxIdx] = true;
    dfs(maxIdx, 0);

    cout << maxWeight << "\n";

    return 0;
}
