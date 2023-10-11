//DFS_BFS 도전 2번: 게임_맵_최단거리
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int>> maps) 
{
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    // 시작 위치와 도착 위치 초기화
    q.push({0, 0});
    dist[0][0] = 1;

    // 상하좌우 이동 방향
    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while (!q.empty()) 
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // 상대 팀 진영에 도착하면 거리 반환
        if (r == n - 1 && c == m - 1) {
            return dist[r][c];
        }

        // 상하좌우 이동
        for (int i = 0; i < 4; i++) 
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // 유효한 위치인지 확인
            if (nr >= 0 && nr < n && nc >= 0 && nc < m) 
            {
                // 벽이 아니고 아직 방문하지 않은 곳인 경우
                if (maps[nr][nc] == 1 && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    // 상대 팀 진영에 도착할 수 없는 경우
    return -1;
}
