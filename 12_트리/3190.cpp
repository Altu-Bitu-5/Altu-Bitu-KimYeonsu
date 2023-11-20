//12_트리 필수2:3190
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Spin {
    int time;
    string dir;

    Spin(int t, const string& d) : time(t), dir(d) {}
};

struct Node {
    int row, col;

    Node(int r, int c) : row(r), col(c) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K, L;
    cin >> N >> K;

    vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));

    // 사과가 있는 위치는 1로 초기화
    for (int i = 0; i < K; i++) {
        int row, col;
        cin >> row >> col;
        map[row][col] = 1;
    }

    cin >> L;

    // 시간에 따라서 회전시킬 방향 queue 생성
    queue<Spin> spin;
    for (int i = 0; i < L; i++) {
        int time;
        string dir;
        cin >> time >> dir;
        spin.push(Spin(time, dir));
    }

    // 0은 북, 1은 동, 2는 남, 3은 서 의미
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    // 초기 (1, 1)에서 시작하고 동쪽을 보고 시작
    int row = 1;
    int col = 1;
    int time = 0;
    int dir = 1;
    queue<Node> q;
    q.push(Node(row, col));
    map[row][col] = 2;

    while (true) {
        int dR = row + dr[dir];
        int dC = col + dc[dir];

        time++;

        if (dR < 1 || dC < 1 || dR > N || dC > N)
            break;
        if (map[dR][dC] == 2)
            break;

        if (map[dR][dC] == 0) {
            Node node = q.front();
            map[node.row][node.col] = 0;
            q.pop();
        }

        if (!spin.empty()) {
            if (time == spin.front().time) {
                Spin s = spin.front();
                spin.pop();

                if (s.dir == "L")
                    dir = (dir - 1 < 0) ? 3 : dir - 1;
                if (s.dir == "D")
                    dir = (dir + 1 > 3) ? 0 : dir + 1;
            }
        }

        map[dR][dC] = 2;
        q.push(Node(dR, dC));
        row = dR;
        col = dC;
    }

    cout << time << "\n";

    return 0;
}
