#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define X first
#define Y second

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> board(n);
    for (int i = 0; i < n; i++) {
        cin >> board[i];
    }

    vector<vector<short>> dist1(n, vector<short>(m, -1));
    vector<vector<short>> dist2(n, vector<short>(m, -1));

    queue<pair<int, int>> Q1;
    queue<pair<int, int>> Q2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'F') {
                Q1.push({ i,j });
                dist1[i][j] = 0;
            }
            else if (board[i][j] == 'J') {
                Q2.push({ i,j });
                dist2[i][j] = 0;
            }
        }
    }

    while (!Q1.empty()) {
        auto cur = Q1.front(); Q1.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] == '#') continue;
            if (dist1[nx][ny] != -1) continue; 
            dist1[nx][ny] = dist1[cur.X][cur.Y] + 1;
            Q1.push({ nx, ny });
        }
    }


    while (!Q2.empty()) {
        auto cur = Q2.front(); Q2.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
                cout << dist2[cur.X][cur.Y] + 1 << "\n";
                return 0;
            }
            if (board[nx][ny] == '#') continue;
            if (dist2[nx][ny] != -1) continue;
            if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[cur.X][cur.Y] + 1) continue;
            dist2[nx][ny] = dist2[cur.X][cur.Y] + 1;
            Q2.push({ nx, ny });
        }
    }

    cout << "IMPOSSIBLE\n";
    return 0;
}
