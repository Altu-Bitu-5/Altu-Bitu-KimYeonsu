//4) 브루트포스 필수3/ 11723번: 집합
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M;
    cin >> M;

    int S = 0; // 집합을 비트로 표현

    while (M--) {
        string command;
        cin >> command;

        if (command == "add") {
            int x;
            cin >> x;
            S |= (1 << x);
        } else if (command == "remove") {
            int x;
            cin >> x;
            S &= ~(1 << x);
        } else if (command == "check") {
            int x;
            cin >> x;
            int result = (S & (1 << x)) ? 1 : 0;
            cout << result << "\n";
        } else if (command == "toggle") {
            int x;
            cin >> x;
            S ^= (1 << x);
        } else if (command == "all") {
            S = (1 << 21) - 1; // 모든 원소를 포함한 집합
        } else if (command == "empty") {
            S = 0; // 공집합
        }
    }

    return 0;
}
