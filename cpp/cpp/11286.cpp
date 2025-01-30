#include<iostream>
#include<algorithm>
#include <queue>
#include<vector>

using namespace std;
int main() {

	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    int N, x;
    cin >> N;

    auto cmp = [](int a, int b) {
        if (abs(a) == abs(b)) return a > b;
        return abs(a) > abs(b);
        };

    priority_queue<int, vector<int>, decltype(cmp)> absHeap(cmp);

    for (int i = 0; i < N; ++i) {
        cin >> x;

        if (x == 0) {
            if (absHeap.empty()) {
                cout << "0\n";
            }
            else {
                cout << absHeap.top() << '\n';
                absHeap.pop();
            }
        }
        else {
            absHeap.push(x);
        }
    }
}