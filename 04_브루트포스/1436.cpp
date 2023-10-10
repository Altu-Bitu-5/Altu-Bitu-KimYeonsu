//4) 브루트포스 필수2/ 1436번: 영화감독 숌
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0; // 종말의 수를 생성하면서 카운트
    int num = 666; // 현재 검사하는 수

    while (true) {
        // 숫자에 6이 연속으로 3개 이상 들어가면 종말의 수로 카운트
        string numStr = to_string(num);
        if (numStr.find("666") != string::npos) {
            count++;
        }

        // N번째 종말의 수를 찾으면 출력하고 종료
        if (count == N) {
            cout << num << endl;
            break;
        }

        num++; // 다음 수 검사
    }

    return 0;
}
