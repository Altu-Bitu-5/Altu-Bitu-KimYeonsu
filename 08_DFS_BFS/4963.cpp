//DFS_BFS 필수 3번: 4963 섬의 개수
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

bool isInside(int x, int y, int w, int h) 
{
    return (x >= 0 && x < w && y >= 0 && y < h);
}

void bfs(int x, int y, vector<vector<int>>& grid, vector<vector<bool>>& visited) 
{
    int w = grid.size();
    int h = grid[0].size();

    queue<pair<int, int>> q;
    q.push(make_pair(x, y));
    visited[x][y] = true;

    while (!q.empty()) 
    {
        int curX = q.front().first;
        int curY = q.front().second;
        q.pop();

        for (int i = 0; i < 8; ++i) 
        {
            int newX = curX + dx[i];
            int newY = curY + dy[i];

            if (isInside(newX, newY, w, h) && grid[newX][newY] == 1 && !visited[newX][newY]) 
            {
                q.push(make_pair(newX, newY));
                visited[newX][newY] = true;
            }
        }
    }
}

int countIslands(vector<vector<int>>& grid) 
{
    int w = grid.size();
    int h = grid[0].size();
    vector<vector<bool>> visited(w, vector<bool>(h, false));
    int islandCount = 0;

    for (int i = 0; i < w; ++i) 
    {
        for (int j = 0; j < h; ++j) 
        {
            if (grid[i][j] == 1 && !visited[i][j]) 
            {
                bfs(i, j, grid, visited);
                islandCount++;
            }
        }
    }

    return islandCount;
}

int main() 
{
    while (true) 
    {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0) {
            break;
        }

        vector<vector<int>> grid(w, vector<int>(h));
        for (int i = 0; i < h; ++i) 
        {
            for (int j = 0; j < w; ++j) 
            {
                cin >> grid[j][i];
            }
        }

        int islandCount = countIslands(grid);
        cout << islandCount << "\n";
    }

    return 0;
}
