//도전과제 2번 9421번: 소수상근수
#include <iostream>
#include <vector>
#include <set>

using namespace std;

//소수 구하기(에라토스테네스의 체)
vector<bool> getPrimes(int n)
{
    vector<bool> is_prime(n+1,true);
    is_prime[0]=is_prime[1] = false;
    
    for(int i=2;i*i<=n;i++){
        if (is_prime[i] == true){
            for (int j=i*i;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    return is_prime;
}
//각 자릿수의 제곱의 합 구하기
int getSum(int num)
{
    int total=0;//각 자리수의 제곱의 합
    int tmp;    //현재 일의 자리수 저장
    while(num != 0){
        tmp = num % 10;
        total += tmp * tmp;
        num /= 10;
    }
    return total;
}
//상근수 구하기
bool isValid(int num)
{
    set<int> visited;
    visited.insert(num);
    
    while(true){
        num = getSum(num);
        if (num == 1){
            return true;
        }
        //현재 각 자리수의 제곱의 합(num)이 이미 나온 수이면 상근수가 아님
        //false 리턴
        if (visited.find(num) != visited.end()){
            return false;
        }
        visited.insert(num);
    }
  
}

//n보다 작거나 같은 모든 소수상근수
vector<int> solution(int n){
    vector<bool> is_prime = getPrimes(n);
    vector<int> result;
    
    for (int i=2;i<=n;i++){
        //i가 소수이면서 상근수이면
        if (is_prime[i] == true && isValid(i)==true)
        //result에 i 추가
        result.push_back(i);
    }
    return result;
}



int main()
{
    //입력
    int n;
    cin >> n;
    
    //연산
     vector<int> result = solution(n);
    
    //출력
    for (int num : result){
        cout << num << "\n";
    }

    return 0;
}
