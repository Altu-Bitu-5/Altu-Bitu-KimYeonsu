//11_투포인터 도전 2번: 2473 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long max_val = 3000000000LL;
long long pick[3];

void solution(vector<long long>& arr, int index) 
{
    int left = index + 1;
    int right = arr.size() - 1;

    while (left < right) 
    {
        long long sum = arr[left] + arr[right] + arr[index];
        long long abs_sum = abs(sum);

        // 두 용액 갱신
        if (abs_sum < max_val) 
        {
            pick[0] = arr[index];
            pick[1] = arr[left];
            pick[2] = arr[right];
            max_val = abs_sum;
        }

        if (sum > 0)
            right--;
        else
            left++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> arr(n);

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 2; ++i) {
        solution(arr, i);
    }

    sort(pick, pick + 3);

    for (int i = 0; i < 3; ++i) {
        cout << pick[i] << ' ';
    }

    return 0;
}
