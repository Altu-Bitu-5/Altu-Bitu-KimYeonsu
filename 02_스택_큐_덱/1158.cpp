//과제1번: 1158번 요세푸스 문제
//큐
#include <iostream>
#include <queue>

using namespace std;

void josephusProblem(int N, int K) {
    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    cout << "<";
    
    while (!q.empty())
    {
        for (int i = 0; i < K - 1; ++i) {
            q.push(q.front());
            q.pop();
        }
        cout << q.front();
        q.pop();
        if (!q.empty()) {
            cout << ", ";
        }
    }
    cout << ">" << "\n";
}

int main() {
    int N, K;
    // 입력
    cin >> N >> K;

    josephusProblem(N, K);

    return 0;
}
