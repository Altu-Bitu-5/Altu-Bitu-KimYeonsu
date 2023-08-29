//과제1번: 19636번 요요 시뮬레이션
#include <iostream>
#include <vector>
//#include <algorithm>
#include <string>

using namespace std;

string yoyo(int x, int y){
    if (x > y){
        return "YOYO";
    }
    else
        return "NO";
}

int main()
{
    int W0, I0, T, D, I, A;

    //입력
    cin >> W0 >> I0 >> T;
    cin >> D >> I >> A;
    
    //기초대사량 고려X
    //W: 체중, O: 기초대사량
    int W=W0;
    int O=I0;
    //연산
    for(int i=0;i<D;i++){
        W=W+I-I0-A;
    }
    //출력
    if( W<=0 || O<=0)
    {
        cout << "Danger Diet\n";
    }
    else{
        cout << W <<" "<< O << "\n";
    }
    
    //기초대사량 고려O
    W=W0;
    O=I0;
    //연산
    for(int i=0;i<D;i++){
        W=W+I-O-A;
        if ((A+O-I) > T){
            //참고) m2 += float(i - (m2 + a)) / 2.0;
                       
            O = O + float(I-A-O)/2.0; 
        }
    }
    
    //출력
    if( W<=0 || O<=0)
    {
        cout << "Danger Diet\n";
    }
    else{
        cout << W <<" "<< O << " " << yoyo(I0, O);
    }

    return 0;
}
