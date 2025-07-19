#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

int dX[6] = { 1, -1, 0, 0, 0, 0 };
int dY[6] = { 0, 0, 1, -1, 0, 0 };
int dZ[6] = { 0, 0, 0, 0, 1, -1 };

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N, H;
    std::cin >> M >> N >> H;

    // 1. 입력받은 크기에 맞게 동적으로 3차원 벡터 생성
    // 2. board 배열 하나로 상태와 방문(날짜)을 모두 관리
    // 접근 순서: board[높이][세로][가로]
    std::vector<std::vector<std::vector<int>>> board(H, std::vector<std::vector<int>>(N, std::vector<int>(M)));
    std::queue<std::tuple<int, int, int>> Q;

    int unripe_tomatoes = 0;

    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                std::cin >> board[h][n][m];

                if (board[h][n][m] == 1) {
                    Q.push({ h, n, m });
                }

                else if (board[h][n][m] == 0) {
                    unripe_tomatoes++;
                }
            }
        }
    }

    if (unripe_tomatoes == 0) {
        std::cout << 0 << "\n";
        return 0;
    }

    int days = 0;
    while (!Q.empty())
    {
        int length = Q.size();
        for (int t = 0; t < length; t++) {
            tuple<int, int, int> Qfront = Q.front();

            for (int i = 0; i < 6; i++) {
                int nZ = std::get<0>(Qfront) + dZ[i];
                int nY = std::get<1>(Qfront) + dY[i];
                int nX = std::get<2>(Qfront) + dX[i]; 

                if (nZ < H && nY < N && nX < M && 0 <= nZ && 0 <= nY&& 0 <= nX && board[nZ][nY][nX] == 0) {
                    board[nZ][nY][nX] = 1;
                    Q.push({ nZ,nY,nX });
                    unripe_tomatoes--;
                }
            }
        

            Q.pop();
            
            if (unripe_tomatoes <= 0) {
                std::cout << days+1 << "\n";
                return 0;
            }
        }
        days++;
    }
    cout << -1;
}