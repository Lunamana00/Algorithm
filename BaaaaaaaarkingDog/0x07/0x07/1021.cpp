#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void Oper_1(deque<int>& deq) {
    deq.pop_front();
}

void Oper_2(deque<int>& deq) {
    deq.push_back(deq.front());
    deq.pop_front();
}

void Oper_3(deque<int>& deq) {
    deq.push_front(deq.back());
    deq.pop_back();
}

int main() {
    int n, m;
    cin >> n >> m;

    deque<int> dq;
    vector<int> targets(m);

    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < m; i++) {
        cin >> targets[i];
    }

    int count = 0;

    for (int i = 0; i < m; i++) {
        int target = targets[i];
        int idx = 0;

        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == target) {
                idx = j;
                break;
            }
        }

        if (idx <= dq.size() / 2) {
            while (dq.front() != target) {
                Oper_2(dq);
                count++;
            }
        }
        else {
            while (dq.front() != target) {
                Oper_3(dq);
                count++;
            }
        }
        Oper_1(dq);
    }

    cout << count << '\n';
    return 0;
}
