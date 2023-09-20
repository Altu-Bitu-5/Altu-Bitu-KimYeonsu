//05_우선순위큐_필수문제3_14235: 크리스마스 선물
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int> giftQueue; // 선물을 담을 우선순위 큐

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        
        if (a == 0)
        {
            if (giftQueue.empty()) {
                cout << "-1" << endl;
            }
            else
            {
                int maxGift = giftQueue.top(); // 가장 가치가 큰 선물을 꺼냄
                cout << maxGift << endl;
                giftQueue.pop(); // 사용한 선물을 큐에서 제거
            }
        }
        else
        {
            // 거점지에서 선물을 충전
            for (int j = 0; j < a; ++j)
            {
                int giftValue;
                cin >> giftValue;
                giftQueue.push(giftValue); // 선물을 큐에 추가
            }
        }
    }

    return 0;
}
