#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define X first
#define Y second

int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N, K, count = 0;
        cin >> M >> N >> K;
        vector<vector<int>> board(N, vector<int>(M, 0));
        vector<vector<int>> vis(N, vector<int>(M, 0));
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (vis[i][j] || board[i][j] != 1) continue;
                queue<pair<int, int>> Q;
                Q.push({ i, j });
                vis[i][j] = 1;
                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();
                    for (int dir = 0; dir < 4; dir++) {
                        int ny = cur.first + dy[dir];
                        int nx = cur.second + dx[dir];
                        if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
                        if (vis[ny][nx] || board[ny][nx] != 1) continue;
                        vis[ny][nx] = 1;
                        Q.push({ ny, nx });
                    }
                }
                count++;
            }
        }
        cout << count << "\n";
    }
    return 0;
}
