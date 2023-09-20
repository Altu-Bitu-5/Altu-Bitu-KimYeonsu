#3
#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1000000; // 최대 범위
vector<bool> isPrime(MAX_N + 1, true); // 소수 여부를 저장하는 배열

void sieveOfEratosthenes() {
    isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님

    for (int p = 2; p * p <= MAX_N; p++) {
        if (isPrime[p]) {
            for (int i = p * p; i <= MAX_N; i += p) {
                isPrime[i] = false; // p의 배수는 소수가 아님
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    sieveOfEratosthenes(); // 소수 판별 배열 초기화

    int n;
    cin >> n;

    while (n != 0) {
        int a, b;
        bool found = false;

        // 골드바흐 파티션 찾기
        for (int i = 2; i <= n / 2; i++) {
            if (isPrime[i] && isPrime[n - i]) {
                a = i;
                b = n - i;
                found = true;
                break;
            }
        }

        if (found) {
            cout << n << " = " << a << " + " << b << "\n";
        } else {
            cout << "Goldbach's conjecture is wrong." << "\n";
        }

        cin >> n; // 다음 테스트 케이스 입력
    }

    return 0;
}
