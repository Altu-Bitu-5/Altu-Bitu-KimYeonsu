//도전과제 1번: 2981번 검문
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
//최대공약수 찾기(반복문)
int getGcd(int a, int b){
    //gcd(a,b) == gcd(a%b, b)
    while(b){
        a %=b;  //a->a%b, b->b, 현재 b>a
        swap(a,b);   //a->b, b->a%b, 현재 a>b
    }
    return a;
}

//모든 M의 약수 찾기
vector<int> sol(int n, vector<int> &nums){
    vector<int> result; //가능한 모든 M 저장
    
    //1. 검문소 사이 간격의 최대공약수(최대 M)
    sort(nums.begin(),nums.end());
    int gcd=nums[1]-nums[0];
    for (int i=2;i<n;i++){
        gcd=getGcd(gcd,nums[i]-nums[i-1]);
    }
    //2. 가능한 모든 M 찾기
    for (int i=2; i*2 <= gcd; i++){
        if(gcd%i == 0){
            result.push_back(i);
        }
    }
    result.push_back(gcd);
    
    return result;
    
}

int main()
{
    //입력
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    
    //연산
    vector<int> result = sol(n, nums);
    
    
    //출력
    for (int i : result){
        cout << i << " ";
    }
    

    return 0;
}
