#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {

    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,temp;
    queue<int> q;
    cin >> N;
    for (int i = 1; i <= N;i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        q.pop();
        if (q.size() == 1) {
            break;
        }
        temp = q.front();
        q.pop();
        q.push(temp);
    }
    cout << q.front();

}
