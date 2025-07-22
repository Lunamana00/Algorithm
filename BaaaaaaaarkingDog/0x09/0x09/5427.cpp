#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>

using namespace std;

#define row first
#define col second

// ��, ��, ��, �� �̵�
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
                board[y][x] = 1; // ������� ���� ��ġ, �ð� 1�� ǥ��
            }
            else if (input == '*') {
                fireQ.push({ y, x });
                board[y][x] = -1; // ��
            }
            else if (input == '#') {
                board[y][x] = -2; // ��
            }
            else {
                board[y][x] = 0;  // ��
            }
        }
    }

    int time = 0;
    while (!sgQ.empty()) {
        time++;

        // 1. ���� ���� Ȯ���Ŵ
        int fire_q_size = fireQ.size();
        for (int i = 0; i < fire_q_size; ++i) {
            pair<int, int> cur = fireQ.front();
            fireQ.pop();

            for (int k = 0; k < 4; ++k) {
                int nRow = cur.row + dRow[k];
                int nCol = cur.col + dCol[k];

                if (nRow >= 0 && nRow < h && nCol >= 0 && nCol < w) {
                    // ���̳� �̹� ���� ���� ���� �ƴ϶�� �� ����
                    if (board[nRow][nCol] != -2 && board[nRow][nCol] != -1) {
                        board[nRow][nCol] = -1;
                        fireQ.push({ nRow, nCol });
                    }
                }
            }
        }

        // 2. ����� �̵�
        int sg_q_size = sgQ.size();
        for (int i = 0; i < sg_q_size; ++i) {
            pair<int, int> cur = sgQ.front();
            sgQ.pop();

            for (int k = 0; k < 4; ++k) {
                int nRow = cur.row + dRow[k];
                int nCol = cur.col + dCol[k];

                // �׸��� ������ ����� Ż�� ����
                if (nRow < 0 || nRow >= h || nCol < 0 || nCol >= w) {
                    cout << time << "\n";
                    return;
                }

                // ����ִ� ��(0)�� ��쿡�� �̵� ����
                if (board[nRow][nCol] == 0) {
                    board[nRow][nCol] = time + 1; // ���� �ð��� �������� ǥ��
                    sgQ.push({ nRow, nCol });
                }
            }
        }
    }

    // ť�� ����µ� Ż������ �������� �Ұ���
    cout << "IMPOSSIBLE\n";
}

int main() {
    // ����� �ӵ� ���
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}