//과제2번: 1431번 시리얼 번호
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//1. 짧은 것 2. 숫자 합이 작은 것 3. 사전 순 (숫자 > 알파벳)

bool cmp(const string &s1, const string &s2){
    if(s1.length() != s2.length()){
        return s1.length() < s2.length();
    }
    
    int sum1=0, sum2=0;
    
    for (char c : s1)
    {
        if (isdigit(c)){
            sum1 += c - '0';
        }
    }
    for (char c : s2)
    {
        if (isdigit(c)){
            sum2 += c - '0';
        }
    }
    if (sum1 != sum2){
        return sum1 < sum2;
    }
   return s1 < s2;
}

int main()
{
    int n;
    cin >> n;
    vector<string> guitar(n);
    
    //입력
    for (int i=0;i<n;i++){
        cin >> guitar[i];
    }
    
    //연산
    sort(guitar.begin(), guitar.end(), cmp);

    //출력
    for(int i=0; i<n; i++){
        cout << guitar[i] << "\n";
    }
    
    return 0;
}
