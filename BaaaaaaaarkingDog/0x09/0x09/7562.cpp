#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define row first
#define col second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    // ����Ʈ�� �̵��� �� �ִ� 8���� ����
    int dX[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int dY[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    while (T--) {
        int L;
        cin >> L;


        vector<vector<int>> dist(L, vector<int>(L, -1));
        queue<pair<int, int>> Q;

        int startY, startX, goalY, goalX;

        // ������ �Է�
        cin >> startY >> startX;
    FileName    Q.push({ startY, startX });
        dist[startY][startX] = 0;

        cin >> goalY >> goalX;

        while (!Q.empty()) {
            pair<int, int> cur = Q.front();
            Q.pop();

            if (cur.row == goalY && cur.col == goalX) {
                cout << dist[cur.row][cur.col] << "\n";
                break;
            }

            // 8���� Ž��
            for (int i = 0; i < 8; i++) {
                int nY = cur.row + dY[i];
                int nX = cur.col + dX[i];

                if (nY >= 0 && nY < L && nX >= 0 && nX < L && dist[nY][nX] == -1) {
                    dist[nY][nX] = dist[cur.row][cur.col] + 1;
                    Q.push({ nY, nX });
                }
            }
        }
    }
}