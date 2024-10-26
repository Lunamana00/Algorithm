#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long int ans=0;
    int N,count;
    cin >> N;
    vector<int> heights(N);
    vector<int> temp_v(N);

    for (int i = 0; i < N; ++i) {
        cin >> heights[i];
    }

    for (int i = N-1; i>=0; --i) {

        count = 0;
        int x = i+1;

        while (x < N) {
            if (heights[x] < heights[i]) {
                count += temp_v[x] + 1;
                x += temp_v[x] + 1;
            }
            else { break; }

        }

        temp_v[i] = count;
        ans += count;
    }
    
    cout << ans;
}
