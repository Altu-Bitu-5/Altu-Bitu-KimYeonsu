//10_이분탐색 도전1: 2343

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    int n, m;
    cin >> n >> m;

    vector<int> lengths(n);

    for (int i = 0; i < n; i++) {
        cin >> lengths[i];
    }

    int left = *max_element(lengths.begin(), lengths.end());
    int right = 10000 * n; // 최대 블루레이 크기

    while (left < right) 
    {
        int mid = (left + right) / 2;
        int count = 1; // 블루레이 개수
        int sum = 0; // 현재 녹화된 길이

        for (int i = 0; i < n; i++) 
        {
            if (sum + lengths[i] > mid) 
            {
                count++;
                sum = 0;
            }
            sum += lengths[i];
        }

        if (count <= m) {
            right = mid;
        } 
        else {
            left = mid + 1;
        }
    }

    cout << left << "\n";

    return 0;
}
