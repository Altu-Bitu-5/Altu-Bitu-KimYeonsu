//그리디알고리즘 도전2: 큰_수_만들기

#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) 
{
  
    string answer = "";
    int size = number.size();
    int keep = size - k; // 결과 문자열의 길이
    int start = 0; // 현재 위치

    for (int i = 0; i < keep; i++) 
    {
        char maxDigit = '0';
        int maxIndex = start;

        // 현재 위치부터 끝까지 탐색하며 가장 큰 숫자를 찾기
        for (int j = start; j <= size - keep + i; j++) 
        {
            if (number[j] > maxDigit) 
            {
                maxDigit = number[j];
                maxIndex = j;
            }
        }

        // 가장 큰 숫자를 결과에 추가하고 다음 탐색 위치 업데이트
        answer += maxDigit;
        start = maxIndex + 1;
    }

    return answer;
}
