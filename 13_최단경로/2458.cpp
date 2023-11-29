//13_필수3: 2458.cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 999999999;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

    for (int i = 1; i <= m; ++i) 
    {
        int a, b;
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int k = 1; k <= n; ++k) 
    {
        for (int i = 1; i <= n; ++i) 
        {
            for (int j = 1; j <= n; ++j) 
            {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int ans = 0;
  
    for (int i = 1; i <= n; ++i) 
    {
        int cnt = 0;
      
        for (int j = 1; j <= n; ++j) 
        {
            if (dist[i][j] != INF || dist[j][i] != INF) {
              cnt++;
            }  
        }
      
        if (cnt == n - 1) ans++;
    }

    cout << ans << "\n";

    return 0;
}
