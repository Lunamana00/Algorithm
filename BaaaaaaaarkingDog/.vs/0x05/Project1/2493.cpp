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

    stack<int> s,s1,s2;
    int N,x,h,recieve,count;
    cin >> N;

    while(N--){
        count = 0;
        cin >> x;
        s.push(x);
        s1 = s;
        h = s1.top();
        while (!(s1.empty())) {
            s1.pop();
            recieve = s1.top();
            if (recieve >= h) {
                cout << s1.size() - count;
            }
            else {
                count++;
            }
        }
    }



}
