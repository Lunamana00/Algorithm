#include <iostream>
#include <string>

using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, num;
    cin >> N;
    string str;


    bool s[21] = { false }; 

    while (N--) {
        cin >> str;

        if (str == "add") {
            cin >> num;
            s[num] = true;
        }
        else if (str == "remove") {
            cin >> num;
            s[num] = false;
        }
        else if (str == "check") {
            cin >> num;
            cout << s[num] << '\n';
        }
        else if (str == "toggle") {
            cin >> num;
            s[num] = !s[num];
        }
        else if (str == "all") {
            fill(begin(s) + 1, end(s), true);
        }
        else if (str == "empty") {
            fill(begin(s) + 1, end(s), false);
        }
    }

}
