// 09_백트래킹 필수 3번: 20055

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> A;
vector<bool> robot;

int simulation();

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    A.resize(2 * n);
    robot.resize(n, false);

    for (int i = 0; i < 2 * n; i++) {
        cin >> A[i];
    }

    int result = simulation();

    cout << result << "\n";

    return 0;
}

int simulation() 
{
    int cnt = 0;
    while (true) 
    {
        int temp = A[2 * n - 1]; // 1. 벨트 한 칸 회전
        for (int i = 2 * n - 1; i > 0; i--) {
            A[i] = A[i - 1];
        }
        A[0] = temp;

        for (int i = n - 1; i > 0; i--) { // 로봇도 벨트와 같이 회전
            robot[i] = robot[i - 1];
        }
        robot[0] = false;

        robot[n - 1] = false;
        for (int i = n - 1; i > 0; i--) 
        { // 2. 로봇 이동 가능하면 이동
            if (robot[i - 1] && !robot[i] && A[i] >= 1) 
            {
                robot[i] = true;
                robot[i - 1] = false;
                A[i]--;
            }
        }

        if (A[0] > 0) 
        { // 3. 올라가는 위치에 로봇 올리기
            robot[0] = true;
            A[0]--;
        }

        cnt++;

        int cntZero = count(A.begin(), A.end(), 0);
        if (cntZero >= m)
            break;
    }

    return cnt;
}
