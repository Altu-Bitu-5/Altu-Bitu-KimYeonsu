//10_이분탐색 도전2: 3079

#include <iostream>
#include <vector>

using namespace std;

long long MIN_TIME = 1;
long long MAX_TIME = 1000000000LL * 1000000000LL;

bool checkInTime(vector<int>& input, int n, int m, long long time) 
{
    long long peopleCnt = 0;
    for (int i = 0; i < n; i++) 
    {
        peopleCnt += (time / input[i]);
        if (peopleCnt >= m) {
            return true;
        }
    }
    return false;
}

long long binarySearch(vector<int>& input, int n, int m) 
{
    long long result = MAX_TIME;
    long long start = MIN_TIME;
    long long end = MAX_TIME;
  
    while (start <= end) {
        long long mid = (start + end) / 2;
        if (checkInTime(input, n, m, mid)) 
        {
            end = mid - 1;
            result = mid;
        } 
        else {
            start = mid + 1;
        }
    }
    return result;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<int> input(n);
  
    for (int i = 0; i < n; i++) {
        cin >> input[i];
    }

    long long answer = binarySearch(input, n, m);
    cout << answer << ""\n;

    return 0;
}
