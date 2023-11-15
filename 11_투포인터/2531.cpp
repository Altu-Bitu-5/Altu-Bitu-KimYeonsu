//11_투포인터 필수 1번: 2531

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 입력값 처리
    int n, d, k, c;
    cin >> n >> d >> k >> c;

    // 결과값 출력
    int eating[3001] = {0};  // 먹은 초밥 종류 관련 배열
    eating[c] = 3001;  // 무료 초밥 종류
    vector<int> sushi(N);
    int count = 1;  // 무료 초밥이 1개 있으므로 default Value = 1

    // 회전 벨트 정보 저장
    for (int i = 0; i < n; ++i){
        cin >> sushi[i];
    }  

    // 회전하지 않았을 때 초밥 종류 구하기
    for (int i = 0; i < k; ++i) 
    {
        int sushiId = sushi[i];
        if (eating[sushiId] == 0){
            count++;
        }  
        eating[sushiId]++;
    }

    int maxCount = count;

    // (n-1)번 회전을 투 포인터를 이용하여 탐색
    for (int i = 0; i < n - 1; ++i) 
    {
        int s_id = sushi[i];  // 처음 먹은 초밥 종류
        int e_id = sushi[(i + k) % n];  // 마지막 + 1번째 먹을 초밥 종류

        if (--eating[s_id] == 0){  // 처음 먹은 초밥 종류 더 이상 없을 때
            count--;
        }  

        if (++eating[e_id] == 1){  // 마지막 + 1번째 먹을 초밥이 처음 먹는 것일 때
            count++;
        }  

        maxCount = max(maxCount, count);  // 최대값 비교
    }

    // 최대 가짓수 출력
    cout << maxCount << "\n";

    return 0;
}
