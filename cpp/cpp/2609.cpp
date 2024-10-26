#include <iostream>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N, gcd, temp1, temp2;
    long long int lcm;

    cin >> M >> N;

    temp1 = M;
    temp2 = N;

    while (temp2 != 0) {
        int remainder = temp1 % temp2;
        temp1 = temp2;
        temp2 = remainder;
    }
    gcd = temp1;

    lcm = static_cast<long long>(M) / gcd * N;

    cout << gcd << '\n' << lcm;
}
