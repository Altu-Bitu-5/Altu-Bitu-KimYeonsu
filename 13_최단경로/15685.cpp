//13_최단경로 필수 1번:15685.cpp

#include <iostream>
#include <vector>

using namespace std;

bool map[101][101] = {false};
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int ans = 0;

void dragonCurve(int x, int y, int d, int g);

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        dragonCurve(x, y, d, g);
    }

    for (int i = 0; i < 100; i++) 
    {
        for (int j = 0; j < 100; j++) 
        {
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) 
            {
                ans++;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}

void dragonCurve(int x, int y, int d, int g) 
{
    vector<int> d_list;
    d_list.push_back(d);

    for (int i = 1; i <= g; i++) 
    {
        for (int j = d_list.size() - 1; j >= 0; j--) {
            d_list.push_back((d_list[j] + 1) % 4);
        }
    }

    map[y][x] = true;
    for (int direction : d_list) 
    {
        x += dx[direction];
        y += dy[direction];
        map[y][x] = true;
    }
}
