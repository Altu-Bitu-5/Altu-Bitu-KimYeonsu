// 09-백트래킹 필수1: 14888.cpp

#include <iostream>
#include <vector>

using namespace std;

int n; // 변경된 변수명
vector<int> numbers;
vector<int> operators(4); // [+, -, *, /]

int max_result = -1e9; // 최댓값 초기화
int min_result = 1e9; // 최솟값 초기화

void backtrack(int index, int result) 
{
    if (index == n) 
    {
        max_result = max(max_result, result);
        min_result = min(min_result, result);
        return;
    }

    for (int i = 0; i < 4; i++) 
    {
        if (operators[i] > 0) 
        {
            operators[i]--;
            int next_result = result;

            if (i == 0) next_result += numbers[index]; // 덧셈
            else if (i == 1) next_result -= numbers[index]; // 뺄셈
            else if (i == 2) next_result *= numbers[index]; // 곱셈
            else if (i == 3) next_result /= numbers[index]; // 나눗셈 (정수 나눗셈)

            backtrack(index + 1, next_result);

            operators[i]++;
        }
    }
}

int main() 
{
    cin >> n;
    numbers.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for (int i = 0; i < 4; i++) {
        cin >> operators[i];
    }

    backtrack(1, numbers[0]); // 첫 번째 수를 초기값으로 설정

    cout << max_result << endl;
    cout << min_result << endl;

    return 0;
}
