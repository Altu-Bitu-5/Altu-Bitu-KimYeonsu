//12_트리 필수1:15681
#include <iostream>
#include <vector>

using namespace std;

int* dp;
vector<int>* tree;
int* visited;
int n;

int func(int idx);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int r, q;
    cin >> r >> q;

    tree = new vector<int>[n + 1];
    dp = new int[n + 1];
    visited = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        tree[i] = vector<int>();
    }

    for (int i = 0; i < n - 1; i++) 
    {
        int x, y;
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }

    // Start!
    visited[r] = 1;
    func(r);

    for (int i = 0; i < q; i++) 
    {
        int idx;
        cin >> idx;
        cout << dp[idx] << "\n";
    }

    delete[] dp;
    delete[] tree;
    delete[] visited;

    return 0;
}

int func(int idx) 
{
    int res = 1;

    if (dp[idx] == 0) 
    {
        vector<int>& list = tree[idx];

        for (int val : list) 
        {
            if (visited[val] == 0) 
            {
                visited[val] = 1;
                res += func(val);
            }
        }

        dp[idx] = res;
    }

    return dp[idx];
}
