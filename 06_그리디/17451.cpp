//그리디알고리즘 필수2: 17451 평행 우주

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    //입력
    int n;
    cin >> n;

    vector<long long> planet(n);
  
    for (int i = 0; i < n; i++) {
        cin >> planet[i];
    }

    long long velocity = planet[n - 1];
  
    for (int i = n - 2; i >= 0; i--)
      {
        if (velocity < planet[i]) {
            velocity = planet[i];
        }
        else if (planet[i] < velocity && velocity % planet[i] != 0) {
            velocity = ((velocity / planet[i]) + 1) * planet[i];
        }
    }

    cout << velocity << "\n";

    return 0;
}
