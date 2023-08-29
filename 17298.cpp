//도전과제1번: 17298번 오큰수
//스택
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    
    int N;
    
    cin >> N;

    vector<int> A(N), result(N, -1);
    stack<int> s;

    //입력
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    //연산
    for (int i = 0; i < N; ++i) {
        while (!s.empty() && A[s.top()] < A[i]) {
            result[s.top()] = A[i];
            s.pop();
        }
        s.push(i);
    }

    //출력
    for (int i = 0; i < N; ++i) {
        cout << result[i] << " ";
    }
    cout << "\n";

    return 0;
}
