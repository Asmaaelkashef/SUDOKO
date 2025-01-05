#include <iostream>
#include <vector>

using namespace std;
 //تتحقق لو ممكن احط الرقم في العواميد والصفوف من غير مكسر القوانين
bool isValid(vector<vector<char>> &board, int row, int col, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] != c && board[row][i] != c && 
            board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != c) {
            return true;
        }
    }
    return false;
}

bool solveSudoku(vector<vector<char>> &board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (solveSudoku(board)) return true;
                        board[i][j] = '.'; 
                    }
                }
                return false; 
            }
        }
    }
    return true;
}

void printBoard(const vector<vector<char>> &board) {
    for (int i = 0; i < 9; i++) {
        if (i > 0 && i % 3 == 0) {
            cout << "------+-------+------\n"; 
        }
        for (int j = 0; j < 9; j++) {
            if (j > 0 && j % 3 == 0) {
                cout << "| "; 
            }
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}
int main() {
    vector<vector<char>> board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    if (solveSudoku(board)) {
        printBoard(board);
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}
