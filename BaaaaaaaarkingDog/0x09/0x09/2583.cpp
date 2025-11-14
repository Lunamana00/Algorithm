#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define X first
#define Y second

int M, N, K, cnt=0;
queue<pair<int,int>> Q;
int dy[4] = {1,0,-1,0};
int dx[4] = {0,1,0,-1};
vector<int> ext;

void printBoard(const vector<vector<int>>& board) {
    cout << "--- Board State ---\n";
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << "\t";

        }
        cout << "\n";
    }
    cout << "-------------------\n";
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> M >> N >> K;

    vector<vector<int>> board(M, vector<int>(N, 0));
    
    int LBX, LBY, RTX, RTY;

    for (int i = 0; i < K; i++){

        cin >> LBX >>  LBY >> RTX >> RTY;

        for (int x = LBX; x < RTX; x++) {
            for (int y = LBY; y < RTY; y++) {
                board[y][x] = -1;
            }
        }
    }
    
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < M; y++) {

            if (board[y][x] == 0) {

                cnt++;
                int ext_v = 0;

                Q.push({x,y});
                board[y][x] = -1;
                pair<int, int> cur;
                int curX, curY;

                while (!Q.empty()){

                    ext_v++;
                    cur = Q.front();
                    Q.pop();

                    for (int i = 0; i < 4; i++) {
                        
                        curX = cur.X + dx[i];
                        curY = cur.Y + dy[i];

                        if (curX >= 0 && curY >= 0 && curX < N && curY < M) {
                            if(board[curY][curX] == 0){
                                
                                Q.push({ curX,curY });
                                board[curY][curX] = -1;
                            }
                        }
                    }
                }
                ext.push_back(ext_v);
            }
        }
    }
    
    cout << cnt << "\n";
    sort(ext.begin(),ext.end());
    for (auto x : ext) {
        cout << x << ' ';
    }
}