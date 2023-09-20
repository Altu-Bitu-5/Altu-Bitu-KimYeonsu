//과제2번: 4949번 균형잡힌 세상
#include <iostream>
#include <stack>
//스택:LIFO
//push():top에 원소 추가, pop(): 삭제, top(): 리턴,
//empty():스택이 비어있으면 true, size(): 스택 사이즈 리턴
#include <string>

using namespace std;

bool isBalanced(const string& expression) {
    stack<char> s;

    for (char c : expression) {
        if (c == '(' || c == '[') {
            s.push(c);
        } else if (c == ')') {
            if (s.empty() || s.top() != '(') {
                return false;
            }
            s.pop();
        } else if (c == ']') {
            if (s.empty() || s.top() != '[') {
                return false;
            }
            s.pop();
        }
    }

    return s.empty();
}

int main() {
    string input;

    while (true) {
        getline(cin, input);
        if (input == ".") {
            break;
        }

        if (isBalanced(input)) {
            cout << "yes" << "\n";
        } else {
            cout << "no" << "\n";
        }
    }

    return 0;
}
