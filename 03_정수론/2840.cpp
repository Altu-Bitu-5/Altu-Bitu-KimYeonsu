//과제2번: 2840번 행운의 바퀴
#include <iostream>
#include <vector>

using namespace std;

typedef pair<int, char> ic;
const int ALPHA = 26;

//출력 합수
string printWheel(int n, int index, vector<char>&wheel){
    string ans = "";
    
    //바퀴 회전과 반대로 출출력
    for (int i = index + n; i>index; i--){
        ans += wheel[i%n];
    }
    return ans;
    
}


string makeWheel(int n, int k, vector<ic>&record){
    vector<char> wheel(n, '?'); //?로 초기화
    vector<bool> is_available(ALPHA, false);    //알파벳 중복 체크 벡터
    
    int index = 0;  //화살표가 가리키는 인덱스
    
    for(int i=0;i<k;i++){
        int s = record[i].first;    //변하는 횟수
        char ch = record[i].second; //회전 후 가리키는 글자
        
        index = (index + s) % n;    //회전 후 화살표 인인덱스
        
        //이미 ch로 채워짐
        if(wheel[index] == ch){
            continue;
        }
        //다른 글자로 채워짐 or 해당 글자가 이미 사용됨
        if (wheel[index] != '?' || is_available[ch-'A']){   //A가 0이 됨
            return "!";
        }
        //비어있는 경우
        wheel[index] = ch;  //해당 칸에 적기
        is_available[ch-'A']=true;  //사용됨
        
    }
    return printWheel(n,index,wheel);
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //입력
    int n,k;
    cin >> n >> k;
    
    vector<ic> record(k);
    for(int i=0;i<k;i++){
        cin >> record[i].first >> record[i].second;
    }
    
    //연산 & 출력
    cout << makeWheel(n, k, record);

    return 0;
}
