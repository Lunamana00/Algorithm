#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    cin >> K;

    const int LIMIT = 8000000;
    vector<bool> isPrime(LIMIT + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= LIMIT; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= LIMIT; j += i) {
                isPrime[j] = false;
            }
        }
    }

    int count = 0;
    for (int i = 2; i <= LIMIT; ++i) {
        if (isPrime[i]) {
            count++;
            if (count == K) {
                cout << i << '\n';
                break;
            }
        }
    }
}
