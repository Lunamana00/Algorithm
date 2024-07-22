#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s;

    int K,x,sum=0;
    cin >> K;

    while (K--)
    {
        cin >> x;
        if (x == 0) {
            s.pop();
        }
        else {
            s.push(x);
        }
    }
    while (!(s.empty())) {
        sum += s.top();
        s.pop();
    }
    cout << sum;
}
