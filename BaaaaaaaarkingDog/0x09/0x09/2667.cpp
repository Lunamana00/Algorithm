#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

string x;
int N, cnt = 0;
queue<pair<int, int>> Q;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };
vector<int> ext;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    vector<vector<int>> board(N, vector<int>(N, 0));

    for (int i = 0; i < N; i++) {

        cin >> x;
        for (int j = 0; j < N; j++) {
            board[i][j] = x[j] - '0';
        }
    }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {

                if (board[i][j] == 1) {
                    cnt++;
                    int ext_v = 0;

                    Q.push({ j, i });
                    board[i][j] = 0;

                    pair<int, int> cur;
                    int curX, curY;

                    while (!Q.empty()) {
                        ext_v++;
                        cur = Q.front();
                        Q.pop();

                        for (int dir = 0; dir < 4; dir++) {
                            curX = cur.X + dx[dir];
                            curY = cur.Y + dy[dir];

                            if (curX >= 0 && curY >= 0 && curX < N && curY < N) {
                                if (board[curY][curX] == 1) {
                                    Q.push({ curX, curY });
                                    board[curY][curX] = 0;
                                }
                            }
                        }
                    }
                    ext.push_back(ext_v);
                }
            }
        }
        cout << cnt << "\n";
        sort(ext.begin(), ext.end());
        for (auto x : ext) {
            cout << x << '\n';
        }
    }