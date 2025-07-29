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

void star(vector<vector<char>>& sBoard, int height,int top,int centor) {

    if (height == 3) {
        sBoard[top][centor] = '*';
        sBoard[top + 1][centor - 1] = '*';
        sBoard[top + 1][centor +1] = '*';
        for (int i = -2; i < 3; i++) {
            sBoard[top +2][centor +i] = '*';
        }

        return;
    }

    height /= 2;
    star(sBoard, height, top, centor);
    star(sBoard, height,top+height,centor-height);
    star(sBoard, height, top + height, centor +height);


}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int height;

    cin >> height;
    vector<vector<char>> sBoard(height, vector<char>(2*height, ' '));

    star(sBoard, height,0, height - 1);
    printBoard(sBoard);

}