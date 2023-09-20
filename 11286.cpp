//05_우선순위큐_도전문제2_11286: 절댓값 힙
#include <iostream>
#include <queue>
#include <vector>
#include <functional>

using namespace std;

struct comp {
    bool operator()(int a, int b) {
        if (abs(a) == abs(b))
            return a > b;
        else
            return abs(a) > abs(b);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, comp> min_heap; // comp 구조체를 비교 함수로 사용

    // 입력
    cin >> n;

    // 연산 & 출력
    while (n--) {
        cin >> x;

        if (x == 0) {
            // 배열이 비어있는 경우
            if (min_heap.empty()) {
                cout << "0\n";
            }
            else {
                // 최소 힙에서 가장 작은 값을 출력하고 해당 값을 제거
                cout << min_heap.top() << "\n";
                min_heap.pop();
            }
        }
        else {
            // 입력 값을 최소 힙에 삽입
            min_heap.push(x);
        }
    }

    return 0;
}
