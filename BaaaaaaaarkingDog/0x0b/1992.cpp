#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(int r, int c, int N, const vector<string>& board) {
    char firstChar = board[r][c];
    for (int i = r; i < r + N; ++i) {
        for (int j = c; j < c + N; ++j) {
            if (board[i][j] != firstChar) {
                return false;
            }
        }
    }
    return true; 
}

void compress(int r, int c, int N, const vector<string>& board, string& result) {
    if (check(r, c, N, board)) {
        result += board[r][c];
    }
    else {
        result += '(';
        int half = N / 2;
        compress(r, c, half, board, result);
        compress(r, c + half, half, board, result);
        compress(r + half, c, half, board, result);
        compress(r + half, c + half, half, board, result); 
        result += ')';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<string> board(N);
    for (int i = 0; i < N; ++i) {
        cin >> board[i];
    }

    string result = "";
    compress(0, 0, N, board, result);

    cout << result << endl;

    return 0;
}