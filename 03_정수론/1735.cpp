#1
#include <iostream>

// 최대 공약수를 구하는 함수
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int numerator1, denominator1, numerator2, denominator2;
    
    // 분자와 분모 입력 받기
    std::cin >> numerator1 >> denominator1;
    std::cin >> numerator2 >> denominator2;
    
    // 두 분수의 합 구하기
    int result_numerator = numerator1 * denominator2 + numerator2 * denominator1;
    int result_denominator = denominator1 * denominator2;
    
    // 합을 기약분수로 만들기 위해 최대 공약수로 나누기
    int common_divisor = gcd(result_numerator, result_denominator);
    
    // 결과 출력
    std::cout << result_numerator / common_divisor << " " << result_denominator / common_divisor << std::endl;
    
    return 0;
}
