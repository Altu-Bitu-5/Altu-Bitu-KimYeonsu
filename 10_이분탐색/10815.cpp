//10_이분탐색 필수1: 10815

#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[500000];

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 숫자 카드 오름차순 정렬
    sort(arr, arr + n);

    cin >> m;

    for (int i = 0; i < m; i++) 
    {
        int num;
        cin >> num;

        // 이분 탐색: 해당 숫자가 있는 경우
        if (binary_search(arr, arr + n, num)) 
        {
            cout << "1 ";
        } else {
            cout << "0 ";
        }
    }

    return 0;
}
