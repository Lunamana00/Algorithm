#include <iostream>
#include <string>
using namespace std;

int main() {
    int N, M, count = 0, result = 0;
    string S;

    cin >> N >> M >> S;

    for (int i = 1; i < M - 1; ++i) {
        if (S[i - 1] == 'I' && S[i] == 'O' && S[i + 1] == 'I') {
            count++;
            if (count == N) {
                result++;
                count--;
            }
            i++;
        }
        else {
            count = 0;
        }
    }

    cout << result << '\n';
}
