#include<iostream>
#include<algorithm>
#include<vector>
#include <unordered_map>

using namespace std;
int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	unordered_map<string, string> map;
	string site, password;
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i) {
        cin >> site >> password;
        map[site] = password;
    }

    for (int i = 0; i < M; ++i) {
        cin >> site;
        cout << map[site] << '\n';
    }
}