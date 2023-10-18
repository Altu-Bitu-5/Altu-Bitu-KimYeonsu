//09_백트래킹 필수 2: 15665

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> arr, nums;
stringstream ss;

void dfs(int cnt, int before);

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m;
    
    arr.resize(m);
    nums.resize(n);
    
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    sort(nums.begin(), nums.end());
    
    dfs(0, -1);
    
    cout << ss.str();
    
    return 0;
}

void dfs(int cnt, int before) 
{
    if (cnt == m) 
    {
        for (int val : arr) {
            ss << val << ' ';
        }
        ss << '\n';
        return;
    }
    
    for (int i = 0; i < n; i++) 
    {
        if (before != nums[i]) 
        {
            arr[cnt] = nums[i];
            dfs(cnt + 1, nums[i]);
        }
    }
}
