//과제3번: 14425번 문자열 집합
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    int count=0;
    
    cin >> n >> m;
    
    vector<string> stringS(n);
    //vector<string> stringA(m);
    //입력
    for (int i=0;i<n;i++){
        cin >> stringS[i];
    }
   
    sort(stringS.begin(), stringS.end());
    
    //입력&연산
    for (int i=0;i<m;i++){
        string stringA;
        cin >> stringA;
        
        if (binary_search(stringS.begin(), stringS.end(), stringA)){
            count++;
        }
    }
    
    //출력
    cout << count;

    return 0;
}
