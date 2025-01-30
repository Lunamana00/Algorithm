#include <iostream>
#include <queue>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    cin >> N;

    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int i = 0; i < N; ++i) {
        cin >> x;

        if (x == 0) {
            if (minHeap.empty()) {
                cout << "0\n";
            }
            else {
                cout << minHeap.top() << '\n';
                minHeap.pop();
            }
        }
        else {
            minHeap.push(x);
        }
    }
}
