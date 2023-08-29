//도전과제2번: 1918번 후위표기식

//push():top에 원소 추가, pop(): 삭제, top(): 리턴,
//empty():스택이 비어있으면 true, size(): 스택 사이즈 리턴

//우선순위:  ( or )
// 1. * or /
// 2. + or -

// ( : push("(")로 스택에 넣기
// top >= 현재: top()   (우선순위 기준)
// ) : (가 나올 때 까지 출력하며 pop()
// 스택이 빌 때까지 pop()

#include <iostream>
#include <stack>
#include <string>

using namespace std;

//우선순위 비교
int cmp(char op) {
    
    if (op == '+' || op == '-') {
        return 1;
    }
    else if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string iToP(const string& in) {
    
    stack<char> s;
    string p;
    
    for (char c : in) {
        
        // 문자(알파벳)
        if (isalpha(c)) { 
            p += c;
        }
        // ( 인 경우: push로 넣기
        else if (c == '(') {
            s.push(c);
        }
        // ) 인 경우: (가 나올 때 까지 출력하며 pop()
        else if (c == ')') {
            while (!s.empty() && s.top() != '(')
            {
                p += s.top();
                s.pop();
            }
            // '(' 제거
            s.pop();
        }
        
        // 연산자 O
        //top >= 현재: top()   (우선순위 기준)
        else { 
            while (!s.empty() && cmp(s.top()) >= cmp(c)) {
                p += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    //스택이 빌 때까지 pop()
    while (!s.empty()) {
        p += s.top();
        s.pop();
    }
    
    return p;
}

int main() {
    
    string in;
    
    //입력
    cin >> in;
    //연산
    string p = iToP(in);
    //출력
    cout << p << "\n";

    return 0;
}
