#include<iostream>
using namespace std;
int dx[4] = { 0,0,1,1 };
int dy[4] = { 0,1,1,0 };
pair<int, int> walk(int n, int x, int y, int dir, int step) {
	if (n == 2) {
		int xpos = ((step - 1) + dir) % 4, ypos = ((step - 1) + 4 - dir) % 4;
		return { x + dx[xpos], y + dy[ypos] };
	}
	int crit = n / 2;
	int curpos = (step - 1) / (crit * crit), nxtxpos = (curpos + dir) % 4, nxtypos = (curpos + 4 - dir) % 4;
	int nxtdir = dir;
	if ((dir % 2 == 0 && curpos == 0) || (dir % 2 == 1 && curpos == 3)) nxtdir = (nxtdir + 1) % 4;
	if ((dir % 2 == 0 && curpos == 3) || (dir % 2 == 1 && curpos == 0)) nxtdir = (nxtdir + 3) % 4;
	return walk(n / 2, x + dx[nxtxpos] * crit, y + dy[nxtypos] * crit, nxtdir, step - curpos * crit * crit);
}
int main() {
	int size, step;
	cin >> size >> step;
	pair<int, int> res = walk(size, 1, 1, 0, step);
	cout << res.first << ' ' << res.second;
}