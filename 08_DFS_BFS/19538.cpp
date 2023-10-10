// DFS_BFS 도전 1번: 19538 루머
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
vector<vector<int>> graph;
queue<int> q;
vector<int> time;
vector<int> neighbor;

void bfs() {
    while (!q.empty()) {
        int nowNode = q.front();
        q.pop();

        for (int next : graph[nowNode]) {
            // 이웃에게 난 루머를 알고있다고 전파
            neighbor[next]++;

            // 시간이 기록 돼 있지 않고 && 본인 노드 수 / 2 <= 본인 이웃 노드가 알고있는 루머 수
            if (time[next] == -1 && (graph[next].size() + 1) / 2 <= neighbor[next]) {
                q.push(next);
                time[next] = time[nowNode] + 1;
            }
        }
    }
}

int main() {
    cin >> n;
    graph.resize(n + 1);
    time.resize(n + 1, -1);
    neighbor.resize(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        int a;
        while (true) {
            cin >> a;
            if (a == 0) break;
            graph[i].push_back(a);
        }
    }

    cin >> m;

    for (int i = 0; i < m; i++) {
        int node;
        cin >> node;
        time[node] = 0;
        q.push(node);
    }

    bfs();

    for (int i = 1; i <= n; i++) {
        cout << time[i];
        if (i != n) cout << " ";
    }

    return 0;
}
