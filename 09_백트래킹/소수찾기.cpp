//09_백트래킹 도전2:소수찾기.cpp

#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n) 
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    for (int i = 3; i * i <= n; i += 2) {
        if (n % i == 0) return false;
    }
    
    return true;
}

void makePermutations(string numbers, string current, vector<bool>& used, set<int>& primes) 
{
    if (!current.empty()) 
    {
        int num = stoi(current);
        if (isPrime(num)) {
            primes.insert(num);
        }
    }
    
    for (int i = 0; i < numbers.length(); i++) 
    {
        if (!used[i]) 
        {
            used[i] = true;
            makePermutations(numbers, current + numbers[i], used, primes);
            used[i] = false;
        }
    }
}

int solution(string numbers) 
{
    int answer = 0;
    set<int> primes;
    vector<bool> used(numbers.length(), false);
    
    makePermutations(numbers, "", used, primes);
    
    for (int prime : primes) {
        answer += isPrime(prime);
    }
    
    return answer;
}
