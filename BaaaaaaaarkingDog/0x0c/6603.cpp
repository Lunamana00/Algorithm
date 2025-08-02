#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void func(vector<int> V, int M, int cur, vector<int>& printV) {

	if (printV.size() == M) {

		for (auto x : printV) {
			cout << x << ' ';
		}
		cout << '\n';

		return;
	}

	for (int i = cur; i < V.size(); i++) {

		printV.push_back(V[i]);
		func(V, M, i+1, printV);
		printV.pop_back();
	}
	return;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int k;
    bool firstCase = true;

    // k를 직접 읽고, 그 값이 0이 아니면 루프를 계속합니다.
    while (std::cin >> k && k != 0) {
        if (!firstCase) {
            std::cout << "\n";
        }

        std::vector<int> S(k);

        for (int i = 0; i < k; ++i) {
            std::cin >> S[i];
        }

        std::vector<int> printV;
        func(S, 6, 0, printV);

        firstCase = false;
    }
    return 0;
}