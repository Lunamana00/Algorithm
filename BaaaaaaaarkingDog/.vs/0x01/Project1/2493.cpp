#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;
/*
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    stack<int> s,s1,s2;
    int N,x,h,recieve,count;
    cin >> N;

    while (N--) {
        cin >> x;
        s.push(x);

    }

}
*/
int main() {
    vector<int> v;
    vector<int>* vp = &v;

    v.push_back(1);
    v.push_back(2);
    v.pop_back();
    for (auto x : v) {
        cout << x << "\n";
    }
}
