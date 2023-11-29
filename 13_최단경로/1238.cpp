//13_최단경로 필수 2번:1238.cpp

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int v, e, x;
    cin >> v >> e >> x;

    vector<vector<pair<int, int>>> graph(v + 1);

    for (int i = 0; i < e; ++i) 
    {
        int a, b, cost;
        cin >> a >> b >> cost;
        graph[a].emplace_back(b, cost);
    }

    auto dijkstra = [&](int start) 
  {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distance(v + 1, INF);

        pq.push({0, start});
        distance[start] = 0;

        while (!pq.empty()) 
        {
            int dist = pq.top().first;
            int now = pq.top().second;
            pq.pop();

            if (distance[now] < dist) continue;

            for (const auto& edge : graph[now]) 
            {
                int node_index = edge.first;
                int node_cost = edge.second;
                int cost = dist + node_cost;

                if (distance[node_index] > cost) 
                {
                    distance[node_index] = cost;
                    pq.push({cost, node_index});
                }
            }
        }

        return distance;
    };

    int result = 0;
  
    for (int i = 1; i <= v; ++i) 
    {
        vector<int> go = dijkstra(i);
        vector<int> back = dijkstra(x);
        result = max(result, go[x] + back[i]);
    }

    cout << result << "\n";

    return 0;
}
