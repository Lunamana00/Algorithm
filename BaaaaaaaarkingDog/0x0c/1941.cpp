#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

char board[5][5];
int answer = 0;
int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };
int picked_indices[7];

bool check_connection() {
    queue<int> q;
    bool q_visited[25] = { false };
    bool is_picked[25] = { false };

    for (int i = 0; i < 7; ++i) {
        is_picked[picked_indices[i]] = true;
    }

    q.push(picked_indices[0]);
    q_visited[picked_indices[0]] = true;
    int count = 1;

    while (!q.empty()) {
        int current_idx = q.front();
        q.pop();

        int r = current_idx / 5;
        int c = current_idx % 5;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            int next_idx = nr * 5 + nc;

            if (nr >= 0 && nr < 5 && nc >= 0 && nc < 5) {
                if (is_picked[next_idx] && !q_visited[next_idx]) {
                    q_visited[next_idx] = true;
                    q.push(next_idx);
                    count++;
                }
            }
        }
    }

    return count == 7;
}

void find_combinations(int depth, int start_index, int s_count) {
    if (depth == 7) {
        if (s_count >= 4) {
            if (check_connection()) {
                answer++;
            }
        }
        return;
    }

    for (int i = start_index; i < 25; ++i) {
        picked_indices[depth] = i;

        int r = i / 5;
        int c = i % 5;

        if (board[r][c] == 'S') {
            find_combinations(depth + 1, i + 1, s_count + 1);
        }
        else {
            find_combinations(depth + 1, i + 1, s_count);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 5; ++i) {
        string row;
        cin >> row;
        for (int j = 0; j < 5; ++j) {
            board[i][j] = row[j];
        }
    }

    find_combinations(0, 0, 0);
    cout << answer << "\n";

    return 0;
}