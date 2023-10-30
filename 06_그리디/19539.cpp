//그리디알고리즘 도전1: 19539 사과나무

#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    //입력
    int N;
    cin >> N;

    vector<int> tree(N);
    int hap = 0; // 나무 길이의 합
    int count = 0; // 2를 뿌릴 수 있는 횟수

    for (int i = 0; i < N; i++) 
    {
        cin >> tree[i];
        count += tree[i] / 2; // 2로 나눈 몫은 2로 뿌릴 수 있는 횟수를 말함
        hap += tree[i]; // 나무 길이의 합
    }

    if (hap % 3 != 0) 
    { // 나무 길이의 합이 3으로 나누어 떨어지지 않을 때
        cout << "NO" << "\n"; // 만들 수 없음
    } 
    else 
    { // 나무 길이의 합이 3으로 나누어 떨어질 때
      
        hap = hap / 3; // 3으로 나눈 몫을 3으로 뿌릴 수 있는 횟수
        if (count >= hap) // 2를 뿌릴 수 있는 횟수가 3으로 뿌릴 수 있는 횟수 이상이여야 함
        {  
            cout << "YES" << "\n";
        }  
        else
        {  
            cout << "NO" << "\n";
        }  
    }

    return 0;
}
