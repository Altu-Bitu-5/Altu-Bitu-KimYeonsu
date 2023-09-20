//05_우선순위큐_도전문제1_1655: 가운데를 말해요
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    priority_queue<int> max_heap; // 중간값 미만의 수를 저장
    priority_queue<int, vector<int>, greater<int>> min_heap; // 중간값 이상의 수를 저장

    while (n--)
    {
        
        int x;
        cin >> x;

        // max_heap의 크기가 min_heap의 크기와 같거나 1 더 크도록 유지
        if (max_heap.size() == min_heap.size()) {
            max_heap.push(x);
        }
        else {
            min_heap.push(x);
        }


        // max_heap와 min_heap의 크기 조절
        if (!max_heap.empty() && !min_heap.empty() && max_heap.top() > min_heap.top())
        {
            int max_val = max_heap.top();
            int min_val = min_heap.top();
            max_heap.pop();
            max_heap.push(min_val);
            min_heap.pop();
            min_heap.push(max_val);
        }

        // max_heap의 top 값이 중간값
        int mid = max_heap.top();

        // 중간값 출력
        cout << mid << "\n";        
    }

    return 0;
}
