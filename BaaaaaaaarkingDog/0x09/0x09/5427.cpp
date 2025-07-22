#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

#define row first
#define col second

// 상, 하, 좌, 우 이동
int dRow[4] = { -1, 1, 0, 0 };
int dCol[4] = { 0, 0, -1, 1 };

void solve() {
    int w, h;
    cin >> w >> h;

    vector<vector<int>> board(h, vector<int>(w, 0));
    queue<pair<int, int>> sgQ;
    queue<pair<int, int>> fireQ;

    for (int y = 0; y < h; y++) {
        string line;
        cin >> line;
        for (int x = 0; x < w; x++) {
            char input = line[x];
            if (input == '@') {
                sgQ.push({ y, x });
                board[y][x] = 1; // 상근이의 시작 위치, 시간 1로 표시
            }
            else if (input == '*') {
                fireQ.push({ y, x });
                board[y][x] = -1; // 불
            }
            else if (input == '#') {
                board[y][x] = -2; // 벽
            }
            else {
                board[y][x] = 0;  // 길
            }
        }
    }

    int time = 0;
    while (!sgQ.empty()) {
        time++;

        // 1. 불을 먼저 확산시킴
        int fire_q_size = fireQ.size();
        for (int i = 0; i < fire_q_size; ++i) {
            pair<int, int> cur = fireQ.front();
            fireQ.pop();

            for (int k = 0; k < 4; ++k) {
                int nRow = cur.row + dRow[k];
                int nCol = cur.col + dCol[k];

                if (nRow >= 0 && nRow < h && nCol >= 0 && nCol < w) {
                    // 벽이나 이미 불이 붙은 곳이 아니라면 불 번짐
                    if (board[nRow][nCol] != -2 && board[nRow][nCol] != -1) {
                        board[nRow][nCol] = -1;
                        fireQ.push({ nRow, nCol });
                    }
                }
            }
        }

        // 2. 상근이 이동
        int sg_q_size = sgQ.size();
        for (int i = 0; i < sg_q_size; ++i) {
            pair<int, int> cur = sgQ.front();
            sgQ.pop();

            for (int k = 0; k < 4; ++k) {
                int nRow = cur.row + dRow[k];
                int nCol = cur.col + dCol[k];

                // 그리드 범위를 벗어나면 탈출 성공
                if (nRow < 0 || nRow >= h || nCol < 0 || nCol >= w) {
                    cout << time << "\n";
                    return;
                }

                // 비어있는 길(0)인 경우에만 이동 가능
                if (board[nRow][nCol] == 0) {
                    board[nRow][nCol] = time + 1; // 다음 시간에 도착함을 표시
                    sgQ.push({ nRow, nCol });
                }
            }
        }
    }

    // 큐가 비었는데 탈출하지 못했으면 불가능
    cout << "IMPOSSIBLE\n";
}

int main() {
    // 입출력 속도 향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}