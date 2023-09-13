//4) 브루트포스 필수1/ 1063번: 킹
#include <iostream>
#include <string>
using namespace std;

int main() {
    char kingCol, stoneCol;
    int kingRow, stoneRow;
    int N;

    cin >> kingCol >> kingRow >> stoneCol >> stoneRow >> N;

    while (N--) {
        string command;
        cin >> command;

        int dx = 0, dy = 0; // 왕의 이동 거리

        if (command == "R") dx = 1;
        else if (command == "L") dx = -1;
        else if (command == "B") dy = -1;
        else if (command == "T") dy = 1;
        else if (command == "RT") { dx = 1; dy = 1; }
        else if (command == "LT") { dx = -1; dy = 1; }
        else if (command == "RB") { dx = 1; dy = -1; }
        else if (command == "LB") { dx = -1; dy = -1; }

        // 왕의 이동
        int newKingCol = kingCol + dx;
        int newKingRow = kingRow + dy;

        // 왕의 이동이 체스판을 벗어나지 않는지 확인
        if (newKingCol >= 'A' && newKingCol <= 'H' && newKingRow >= 1 && newKingRow <= 8) {
            // 돌의 위치 업데이트
            if (newKingCol == stoneCol && newKingRow == stoneRow) {
                int newStoneCol = stoneCol + dx;
                int newStoneRow = stoneRow + dy;

                // 돌의 이동이 체스판을 벗어나지 않으면 돌의 위치 업데이트
                if (newStoneCol >= 'A' && newStoneCol <= 'H' && newStoneRow >= 1 && newStoneRow <= 8) {
                    stoneCol = newStoneCol;
                    stoneRow = newStoneRow;
                }
            }

            kingCol = newKingCol;
            kingRow = newKingRow;
        }
    }

    cout << kingCol << kingRow << '\n';
    cout << stoneCol << stoneRow << '\n';

    return 0;
}
