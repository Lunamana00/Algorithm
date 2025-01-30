#include <iostream>
#include <algorithm>

#include <vector>
#include <string>

#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    deque<int> deq;
    int N,x;
    string order,out_str;
    cin >> N;

    while (N--) {
        cin >> order;
        if (order == "push_back") {
            cin >> x;
            deq.push_back(x);
        }
        else if (order == "push_front") {
            cin >> x;
            deq.push_front(x);
        }
        else if (order == "pop_back") {
            if (!(deq.empty())) {
                cout << deq.back();
                cout << '\n';
                deq.pop_back();
            }
            else {
                cout << -1;
                cout << '\n';
            }
        }
        else if (order == "pop_front") {
            if (!(deq.empty())) {
                cout << deq.front();
                cout << '\n';
                deq.pop_front();
            }
            else {
                cout << -1;
                cout << '\n';
            }
        }
        else if (order == "back") {
            if (!(deq.empty())) {
                cout << deq.back();
                cout << '\n';
            }
            else {
                cout << -1;
                cout << '\n';
            }
        }
        else if (order == "front") {
            if (!(deq.empty())) {
                cout<< deq.front();
                cout << '\n';
            }
            else {
                cout << -1;
                cout << '\n';
            }
        }
        else if (order == "size") {
            cout << deq.size();
            cout << '\n';
        }
        else if (order == "empty") {
            if (!(deq.empty())) {
                cout << 0;
                cout << '\n';
            }
            else {
                cout << 1;
                cout << '\n';
            }
        }
        
    }
}
