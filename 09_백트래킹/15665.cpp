//09_백트래킹 필수 2: 15665

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int n, m;
vector<int> arr;
vector<int> printArr;
stringstream sb;

void dfs(int depth) 
{
    if (depth == m) 
    {
        for (int i = 0; i < m; i++) {
            sb << printArr[i] << " ";
        }
        sb << "\n";
        return;
    }

    int before = -1;
    for (int i = 0; i < n; i++) 
    {
        int now = arr[i];
        if (before != now) 
        {
            before = now;
            printArr[depth] = arr[i];
            dfs(depth + 1);
        }
    }
}

int main() 
{
    cin >> n >> m; // 변수명 변경

    arr.resize(n);
    printArr.resize(m);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    dfs(0);

    cout << sb.str();

    return 0;
}
