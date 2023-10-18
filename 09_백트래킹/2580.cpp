//09_백트래킹 도전1번:2580.cpp

#include <iostream>

using namespace std;

const int n = 9;
int sudoku[n][n];

bool solveSudoku();
bool isSafe(int row, int col, int num);
void printSudoku();

int main() 
{
    // 스도쿠 판 입력
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) {
            cin >> sudoku[i][j];
        }
    }

    // 스도쿠 문제를 풀고 결과 출력
    if (solveSudoku()) {
        printSudoku();
    } 
    else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

bool solveSudoku() 
{
    int row, col;

    // 빈 칸을 찾아서 row, col 변수에 저장
    bool emptyCell = false;
    for (row = 0; row < n; row++) 
    {
        for (col = 0; col < n; col++) 
        {
            if (sudoku[row][col] == 0) 
            {
                emptyCell = true;
                break;
            }
        }
        if (emptyCell) 
          break;
    }

    // 모든 빈 칸이 채워진 경우에 대한 종료 조건
    if (!emptyCell) {
        return true;
    }

    // 1부터 9까지의 숫자 중 가능한 숫자를 찾아서 시도
    for (int num = 1; num <= 9; num++) 
    {
        if (isSafe(row, col, num)) 
        {
            sudoku[row][col] = num;

            // 재귀적으로 다음 빈 칸을 채우기
            if (solveSudoku()) {
                return true;
            }

            // 현재 시도가 실패하면 다시 0으로 초기화
            sudoku[row][col] = 0;
        }
    }

    return false; // 모든 숫자 시도 후 해결 방법이 없는 경우
}

bool isSafe(int row, int col, int num) 
{
    // 같은 열에 중복된 숫자가 있는지 검사
    for (int i = 0; i < n; i++) 
    {
        if (sudoku[i][col] == num) {
            return false;
        }
    }

    // 같은 행에 중복된 숫자가 있는지 검사
    for (int j = 0; j < n; j++) 
    {
        if (sudoku[row][j] == num) {
            return false;
        }
    }

    // 3x3 박스 내에 중복된 숫자가 있는지 검사
    int boxRow = row - row % 3;
    int boxCol = col - col % 3;
    for (int i = boxRow; i < boxRow + 3; i++) 
    {
        for (int j = boxCol; j < boxCol + 3; j++) 
        {
            if (sudoku[i][j] == num) {
                return false;
            }
        }
    }

    return true; // 중복된 숫자가 없을 경우
}

void printSudoku() 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cout << sudoku[i][j];
            if (j < n - 1) {
                cout << ' ';
            }
        }
        cout << "\n";
    }
}
