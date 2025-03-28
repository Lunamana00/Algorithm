#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,count1=0,count2=0;
    cin >> N;

    vector<vector<int>> vis1(N, vector<int>(N, 0));
    vector<vector<int>> vis2(N, vector<int>(N, 0));
    vector<string> board(N);

    for (int i = 0; i < N; i++) {
        cin >> board[i];
    }
    
    queue <pair<int,int>> Q;
    char save;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (vis1[row][col] == 0) {
                save = board[row][col];
                Q.push({ col,row });
                while (!Q.empty()){
                    auto cur = Q.front(); Q.pop();
                    for (int i = 0; i < 4;i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N) {
                            continue;
                        }
                        if (board[ny][nx] != save || vis1[ny][nx] == 1) {
                            continue;
                        }
                        vis1[ny][nx] = 1;
                        Q.push({ nx,ny });
                    }
                }
                count1++;
            }
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (vis2[row][col] == 0) {
                save = board[row][col];
                Q.push({ col,row });
                while (!Q.empty()) {
                    auto cur = Q.front(); Q.pop();
                    for (int i = 0; i < 4;i++) {
                        int nx = cur.X + dx[i];
                        int ny = cur.Y + dy[i];
                        if (nx < 0 || nx >= N || ny < 0 || ny >= N|| vis2[ny][nx] == 1) {
                            continue;
                        }
                        if (save == 'B') {
                            if (board[ny][nx] != 'B') {
                                continue;
                            }
                        }
                        else {
                            if (board[ny][nx] == 'B') {
                                continue;
                            }
                        }
                        vis2[ny][nx] = 1;
                        Q.push({ nx,ny });
                    }
                }
                count2++;
            }
        }
    }
    cout << count1<< ' '<< count2;
}
