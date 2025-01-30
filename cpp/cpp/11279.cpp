#include <iostream>
#include <queue>
using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, x;
    cin >> N;

    priority_queue<int> maxHeap;

    for (int i = 0; i < N; ++i) {
        cin >> x;

        if (x == 0) {
            if (maxHeap.empty()) {
                cout << "0\n";
            }
            else {
                cout << maxHeap.top() << '\n';
                maxHeap.pop();
            }
        }
        else {
            maxHeap.push(x);
        }
    }
}
