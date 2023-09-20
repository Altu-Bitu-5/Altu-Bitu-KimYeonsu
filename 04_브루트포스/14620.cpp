//04_브루트포스 도전2번/ 14620 꽃길
#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200 * 15;

int getScore(int r, int c, vector<vector<int>>& gr) {
    return gr[r - 1][c] + gr[r][c - 1] + gr[r + 1][c] + gr[r][c + 1] + gr[r][c];
}

int solution(int n, vector<vector<int>>& gr) {
    int answer = MAX;
    
    n -= 2; // 테두리를 제외한 칸 (n-2) * (n-2) 칸 중에 3칸을 고름
    
    for (int r1 = 1; r1 <= n; r1++) {
        for (int c1 = 1; c1 <= n; c1++) {
            for (int r2 = 1; r2 <= n; r2++) {
                for (int c2 = 1; c2 <= n; c2++) {
                    if (abs(r1 - r2) + abs(c1 - c2) <= 2) {
                        continue; // 겹치는 경우 제외
                    }
                    
                    for (int r3 = 1; r3 <= n; r3++) {
                        for (int c3 = 1; c3 <= n; c3++) {
                            if (abs(r1 - r3) + abs(c1 - c3) <= 2 || abs(r2 - r3) + abs(c2 - c3) <= 2) {
                                continue; // 겹치는 경우 제외
                            }
                            
                            int score = getScore(r1, c1, gr) + getScore(r2, c2, gr) + getScore(r3, c3, gr);
                            answer = min(answer, score);
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}

int main() {
    int n;
    vector<vector<int>> gr;
    
    // 입력
    cin >> n;
    gr.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> gr[i][j];
        }
    }
    
    // 연산 & 출력
    cout << solution(n, gr);
    return 0;
}
