//12_트리 도전2:24545
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> tree;
vector<int> subtreeSize;
vector<bool> visited;

// DFS를 통해 서브트리의 크기 구하기
int getSubtreeSize(int node, int parent) 
{
    int size = 1;

    for (int child : tree[node]) 
    {
        if (!visited[child] && child != parent) {
            size += getSubtreeSize(child, node);
        }
    }

    subtreeSize[node] = size;
    return size;
}

// 정점 삭제를 통해 Y-트리의 최대 크기 구하기
int getMaxYTreeSize(int n) 
{
    int maxYTreeSize = 0;

    for (int i = 1; i <= n; ++i) 
    {
        visited.assign(n + 1, false);

        // i번 정점 삭제
        visited[i] = true;

        for (int j = 1; j <= n; ++j) 
        {
            if (!visited[j]) 
            {
                int remainingVertices = n - subtreeSize[j];
                maxYTreeSize = max(maxYTreeSize, remainingVertices);
                break;
            }
        }
    }

    return maxYTreeSize;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    tree.resize(n + 1);
    subtreeSize.resize(n + 1, 0);
    visited.resize(n + 1, false);

    for (int i = 0; i < n - 1; ++i) 
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // 각 정점에서 서브트리의 크기 구하기
    for (int i = 1; i <= n; ++i) 
    {
        if (!visited[i]) {
            getSubtreeSize(i, 0);
        }
    }

    int result = getMaxYTreeSize(n);
    cout << result << "\n";

    return 0;
}
