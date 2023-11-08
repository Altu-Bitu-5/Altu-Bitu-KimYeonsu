//10_이분탐색 필수3: 16401

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m, n, result;
vector<int> arr;

void bs(int s, int e) 
{
    if (s > e)
        return;
    int mid = (s + e) / 2;
    int cnt = 0;

    for (int i = 0; i < n; i++)
        cnt += arr[i] / mid;

    if (cnt >= m) 
    {
        if (result < mid){
            result = mid;
        }  
        bs(mid + 1, e);
    } 
    else {
        bs(s, mid - 1);
    }
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    bs(1, arr[n - 1]);

    cout << result << "\n";

    return 0;
}
