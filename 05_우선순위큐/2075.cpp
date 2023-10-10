//05_우선순위큐_필수문제1_2075:N번째 큰 수
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    // 우선순위 큐를 사용하여 N개의 큰 수를 저장
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int num;
            cin >> num;

            // 큐에 N개의 큰 수를 유지
            if (pq.size() < N) {
                pq.push(num);
            } else if (num > pq.top()) {
                pq.pop();
                pq.push(num);
            }
        }
    }

    cout << pq.top() << "\n";

    return 0;
}
