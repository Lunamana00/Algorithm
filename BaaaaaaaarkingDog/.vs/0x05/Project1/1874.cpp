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

    stack<int> s1;
    vector<int> v;
    vector<char> v2;
    int N,x,flag=1;
    cin >> N;
    int num2 = 1;

    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }

    for (int i = 0; i < N; i++) {
        int num = v[i];
        
        while (true) {
            if(num2 > N+1){
                flag = 0;
                break;
            }else if (!(s1.empty()) && s1.top() == num) {
                s1.pop();
                v2.push_back('-');
                break;
            }
            else {
                s1.push(num2++);
                v2.push_back('+');
            }
        }
        if (flag == 0) {
            break;
        }
    }

    if (flag == 0) {
        cout << "NO";
    }else {
        for (auto x : v2) {
            cout << x << '\n';
        }
    }
}
