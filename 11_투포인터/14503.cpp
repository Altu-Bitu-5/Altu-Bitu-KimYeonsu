//11_투포인터 필수 3번: 14503.cpp

#include <iostream>
#include <vector>

using namespace std;

int n, m, r, c, d;
int arr[50][50];
int count = 1; // 시작 지점은 항상 청소되어 있지 않음
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void clean(int x, int y, int dir) 
{
    arr[x][y] = -1;

    for (int i = 0; i < 4; ++i) 
    {
        dir = (dir + 3) % 4;

        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m) 
        {
            if (arr[nx][ny] == 0) 
            {
                count++;
                clean(nx, ny, dir);
                return;
            }
        }
    }

    int d = (dir + 2) % 4; // 반대 방향으로 후진
    int bx = x + dx[d];
    int by = y + dy[d];
    if (bx >= 0 && by >= 0 && bx < n && by < m && arr[bx][by] != 1) {
        clean(bx, by, dir); // 후진이니까 바라보는 방향은 유지
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> r >> c >> d;

    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < m; ++j) {
            cin >> arr[i][j];
        }
    }

    clean(r, c, d);
    cout << count << "\n";

    return 0;
}
