//DFS_BFS 필수 1번: 1325 효율적인 해킹
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> adj;
vector<bool> visit;
vector<int> result;
int maxCount = -1;

void bfs(int start) 
{
    queue<int> q;
    q.push(start);
    visit[start] = true;
    int count = 0;

    while (!q.empty()) 
    {
        int node = q.front();
        q.pop();

        for (int next : adj[node]) 
        {
            if (!visit[next]) 
            {
                q.push(next);
                visit[next] = true;
                count++;
            }
        }
    }

    result[start] = count;
    maxCount = max(maxCount, count);
}

int main() 
{
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visit.resize(n + 1, false);
    result.resize(n + 1, 0);

    for (int i = 0; i < m; i++) 
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) 
    {
        fill(visit.begin(), visit.end(), false);
        bfs(i);
    }

    for (int i = 1; i <= n; i++) 
    {
        if (result[i] == maxCount) {
            cout << i << " ";
        }
    }

    return 0;
}
