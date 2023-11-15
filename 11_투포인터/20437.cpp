//11_투포인터 도전 1번: 20437

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) 
    {
        string str;
        cin >> str;

        int k;
        cin >> k;

        if (k == 1) 
        { // k가 1일 때
            cout << "1 1\n";
            continue;
        }

        vector<int> alpha(26, 0); // 알파벳 별 개수를 저장한다.
        for (char c : str) {
            alpha[c - 'a']++;
        }

        int minLen = numeric_limits<int>::max();
        int maxLen = -1;
        for (int j = 0; j < str.length(); ++j) 
        {
            if (alpha[str[j] - 'a'] < k) continue;

            int count = 1;
            for (int l = j + 1; l < str.length(); ++l) 
            {
                if (str[j] == str[l]) count++;
                if (count == k) 
                {
                    minLen = min(minLen, l - j + 1);
                    maxLen = max(maxLen, l - j + 1);
                    break;
                }
            }
        }

        if (minLen == numeric_limits<int>::max() || maxLen == -1) {
            cout << "-1\n";
        } 
        else {
            cout << minLen << " " << maxLen << "\n";
        }
    }

    return 0;
}
