#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printBoard(const std::vector<std::vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }
}

void star(vector<vector<char>> &sBoard, int N, int r, int c) {

    if (N == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == 1 && j == 1) {
                    sBoard[r + i][c + j] = ' ';
                    continue;
                }
                sBoard[r + i][c + j] = '*';
            }
        }
        return;
    }
    
    int div3 = N / 3;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == 1 && j == 1) {
                continue;
            }
            
            
            star(sBoard, div3, r+ div3 *i, c+ div3 * j);
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    

    int N;

    cin >> N;
    vector<vector<char>> sBoard(N,vector<char>(N,' '));
    star(sBoard,N,0,0);
    
    printBoard(sBoard);

}