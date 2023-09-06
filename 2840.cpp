#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    string wheel = "NITAVRHO"; // 초기 바퀴 상태
    vector<pair<int, char>> rotations; // 회전 정보를 저장할 벡터

    for (int i = 0; i < K; i++) {
        int S;
        char stop_at;
        cin >> S >> stop_at;
        
        rotations.push_back({S, stop_at});
    }

    // 마지막 회전에서 바퀴에 적힌 알파벳을 계산
    for (int i = K - 1; i >= 0; i--) {
        int S = rotations[i].first;
        char stop_at = rotations[i].second;
        
        int arrow_position = S % N; // 화살표의 최종 위치
        int stop_index = (N - arrow_position) % N; // 회전을 멈추는 위치의 인덱스

        wheel[stop_index] = stop_at;
        N--; // 바퀴 크기 감소
    }

    cout << wheel << endl;

    return 0;
}
