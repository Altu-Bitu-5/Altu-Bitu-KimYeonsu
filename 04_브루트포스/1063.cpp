//4) 브루트포스 필수1/ 1063번: 킹
#include <iostream>
#include <string>
#include <vector>
using namespace std;

typedef pair<char, char> cc;

cc move(string input, char x, char y) {
    for (char how : input) {
        if (how == 'R') {
            x++;
        }
        else if (how == 'L') {
            x--;
        }
        else if (how == 'B') {
            y--;
        }
        else { // T
            y++;
        }
    }
    return { x, y };
}

bool checkRange(cc position) {
    if (position.first < 'A' || position.first > 'H' || position.second < '1' || position.second > '8') {
        return false;
    }
    return true;
}

bool isSame(cc k, cc s) {
    return (k.first == s.first && k.second == s.second);
}

int main() {
    cc king, stone;
    int N;

    cin >> king.first >> king.second >> stone.first >> stone.second >> N;

    while (N--) {
        string command;
        cin >> command;

        cc newKing = move(command, king.first, king.second);

        if (checkRange(newKing)) {
            if (isSame(newKing, stone)) {
                cc newStone = move(command, stone.first, stone.second);
                if (checkRange(newStone)) {
                    stone = newStone;
                    king = newKing;
                }
            }
            else {
                king = newKing;
            }
        }
    }

    cout << king.first << king.second << '\n';
    cout << stone.first << stone.second << '\n';

    return 0;
}
