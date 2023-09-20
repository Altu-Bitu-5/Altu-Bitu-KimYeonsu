//04_브루트포스 도전 1번/1052: 물병
#include <iostream>
using namespace std;

const int MAX = 26;     // 2^26 > 10^7

// 물의 양을 이진수로 표현했을 때 1의 개수를 계산하는 함수
int bitCount(int n) {
    int count = 0;
    while (n > 0) {
        if (n % 2 == 1) {
            count++;
        }
        n /= 2;
    }
    return count;
}

int minCount(int n, int k) {
    if (n <= k) {
        return 0;
    }
    
    int moves = 0;   // 이동 횟수
    
    while (bitCount(n) > k) {
        n++; // 1리터 짜리 물병을 하나 추가
        moves++;
    }
    
    return moves;
}

int main() {
    int n, k;
    
    // 입력
    cin >> n >> k;
    
    // 연산 & 출력
    int result = minCount(n, k);
    cout << result << endl;
    
    return 0;
}
