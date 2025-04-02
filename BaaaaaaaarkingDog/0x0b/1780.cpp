#include <iostream>
#include <vector>
using namespace std;

vector<int> v_countPaper(3);

void div(int N, int SP_row, int SP_col, vector<vector<int>>& paper) {
	int save = paper[SP_row][SP_col];
	bool isSame = true;

	for (int i = SP_row; i < SP_row + N; i++) {
		for (int j = SP_col; j < SP_col + N; j++) {
			if (paper[i][j] != save) {
				isSame = false;
				break;
			}
		}
		if (!isSame) break;
	}

	if (isSame) {
		v_countPaper[save + 1]++;
		return;
	}

	int newSize = N / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			div(newSize, SP_row + i * newSize, SP_col + j * newSize, paper);
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	vector<vector<int>> paper(N, vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> paper[i][j];
		}
	}

	div(N, 0, 0, paper);

	for (int i = 0; i < 3; i++) {
		cout << v_countPaper[i] << '\n';
	}
}