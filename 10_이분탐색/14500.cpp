//10_이분탐색 필수2: 14500

#include <iostream>
#include <vector>

using namespace std;

int n, m, ans;
vector<vector<int>> map;
vector<vector<bool>> visit;
vector<int> dy = {-1, 1, 0, 0};
vector<int> dx = {0, 0, -1, 1};

void dfs(int y, int x, int cnt, int sum, vector<vector<bool>>& visit) 
{
    if (cnt >= 4) 
    {
        ans = max(ans, sum);
        return;
    }

    for (int k = 0; k < 4; k++) 
    {
        int ny = y + dy[k];
        int nx = x + dx[k];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || visit[ny][nx]) {
            continue;
        }

        visit[ny][nx] = true;
        dfs(ny, nx, cnt + 1, sum + map[ny][nx], visit);
        visit[ny][nx] = false;
    }
}

void check(int y, int x) 
{
    if (y < n - 2 && x < m - 1){
        ans = max(ans, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x + 1]);
    }

    if (y < n - 2 && x > 0){
        ans = max(ans, map[y][x] + map[y + 1][x] + map[y + 2][x] + map[y + 1][x - 1]);
    }

    if (y < n - 1 && x < m - 2){
        ans = max(ans, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1]);
    }

    if (y > 0 && x < m - 2){
        ans = max(ans, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1]);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    map.assign(n, vector<int>(m));
    visit.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            visit[i][j] = true;
            dfs(i, j, 1, map[i][j], visit);
          
            visit[i][j] = false;
            check(i, j);
        }
    }

    cout << ans << "\n";

    return 0;
}
