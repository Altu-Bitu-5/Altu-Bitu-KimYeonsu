//DFS_BFS 필수 2번: 2615 오목
#include <iostream>
#include <vector>

using namespace std;

bool isInside(int x, int y) 
{
    return x >= 0 && x < 19 && y >= 0 && y < 19;
}

int checkWin(const vector<vector<int>>& board, int x, int y) {
    int dx[4] = {1, 0, 1, -1}; // 가로, 세로, 대각선 방향을 나타내는 x 좌표 변화값
    int dy[4] = {0, 1, 1, 1};  // 가로, 세로, 대각선 방향을 나타내는 y 좌표 변화값

    for (int dir = 0; dir < 4; ++dir) 
    {
        int count = 1;  // 연속된 바둑알의 개수 초기화
        int nx = x + dx[dir];  // 다음 검사할 x 좌표 계산
        int ny = y + dy[dir];  // 다음 검사할 y 좌표 계산

        while (isInside(nx, ny) && board[nx][ny] == board[x][y]) 
        {
            count++;  // 같은 색 바둑알 개수 증가
            nx += dx[dir];  // 다음 검사할 x 좌표 갱신
            ny += dy[dir];  // 다음 검사할 y 좌표 갱신
        }

        if (count == 5) {  // 연속된 바둑알이 5개인 경우
            // 승부가 결정된 경우
            int prev_x = x - dx[dir];
            int prev_y = y - dy[dir];
            if (!isInside(prev_x, prev_y) || board[prev_x][prev_y] != board[x][y]) {
                // 승리한 플레이어의 색과 다른 색이 놓인 경우에만 승부로 인정
                return board[x][y];
            }
        }
    }

    return 0;  // 승리 조건 미충족
}

int main() 
{
    vector<vector<int>> board(19, vector<int>(19, 0));  // 19x19 바둑판 초기화

    // 바둑판 상태 입력
    for (int i = 0; i < 19; ++i) 
    {
        for (int j = 0; j < 19; ++j) {
            cin >> board[i][j];  // 각 위치의 바둑알 상태 입력
        }
    }

    for (int i = 0; i < 19; ++i) 
    {
        for (int j = 0; j < 19; ++j) 
        {
            if (board[i][j] != 0) 
            {  // 빈 칸이 아닌 경우
                int result = checkWin(board, i, j);  // 승리 여부 확인
                if (result != 0) 
                {  // 승부가 결정된 경우
                    cout << result << '\n' << i + 1 << ' ' << j + 1 << '\n';  // 승리한 플레이어와 위치 출력
                    return 0;
                }
            }
        }
    }

    cout << "0\n";  // 아직 승부가 결정되지 않은 경우
    return 0;
}
