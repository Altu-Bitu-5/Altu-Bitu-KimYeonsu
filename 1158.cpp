//과제1번: 1158번 요세푸스 문제
//큐
#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    queue<int> q;
    
    while (N--) {
        string command;
        cin >> command;
        
        if (command == "push") {
            int X;
            cin >> X;
            q.push(X);
        } else if (command == "pop") {
            if (!q.empty()) {
                cout << q.front() << endl;
                q.pop();
            } else {
                cout << -1 << endl;
            }
        } else if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "empty") {
            cout << (q.empty() ? 1 : 0) << endl;
        } else if (command == "front") {
            if (!q.empty()) {
                cout << q.front() << endl;
            } else {
                cout << -1 << endl;
            }
        } else if (command == "back") {
            if (!q.empty()) {
                cout << q.back() << endl;
            } else {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
