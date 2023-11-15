//11_투포인터 필수 2번: 20922

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int limit[100001] = {0};
    vector<int> num(n);

    for (int i = 0; i < n; ++i) {
        cin >> num[i];
    }

    int maxLen = 0;
    int startIdx = 0;
    int endIdx = 0;
    limit[num[startIdx]]++;

    for (int i = 1; i < n; ++i) 
    {
        if (limit[num[i]] < k) 
        {
            endIdx = i;
            limit[num[endIdx]]++;
            maxLen = max(endIdx - startIdx + 1, maxLen);
        } 
        else 
        {
            while (true) 
            {
                if (num[startIdx] == num[i]) 
                {
                    startIdx++;
                    endIdx = i;
                    break;
                } 
                else 
                {
                    limit[num[startIdx]]--;
                    startIdx++;
                }
            }
        }
    }

    cout << maxLen << "\n";

    return 0;
}
