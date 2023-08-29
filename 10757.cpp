//과제3번: 10757번 큰수 A+B
//덱
#include <iostream>
#include <deque>  //덱
#include <algorithm>

using namespace std;

int main() {
    
    string A, B;
  
    //입력
    cin >> A >> B;

    deque<int> result;
    int carry = 0;

    // 덱의 뒤에서부터 각 자리수를 더한 후, 올림 처리
    for (int i = A.size() - 1, j = B.size() - 1; i >= 0 || j >= 0 || carry; --i, --j) {
        int digitA = i >= 0 ? A[i] - '0' : 0;
        int digitB = j >= 0 ? B[j] - '0' : 0;
        int sum = digitA + digitB + carry;
        result.push_front(sum % 10);
        carry = sum / 10;
    }

    //출력
    for (int digit : result) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
