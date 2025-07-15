#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);


    int N,count=0;
    cin >> N;

    for (int i = 0; i < N; i++) {

        stack<char> S_c1;
        string s1;
        cin >> s1;

        for (int j = 0; j < s1.length(); j++) {
            if (S_c1.empty()) {
                S_c1.push(s1[j]);
                continue;
            }

            if (S_c1.top() == s1[j]) {
                S_c1.pop();
            }
            else {
                S_c1.push(s1[j]);
            }
        }

        if (S_c1.empty()) {
            count++;
        }
    }
    cout << count;
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  