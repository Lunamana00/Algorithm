#include <iostream>
#include <vector>
#include <numeric> // iota 사용 (필수는 아님)

void solve() {
    int N;
    std::cin >> N;

    // N이 0이면 아무것도 입력받지 않고 0을 출력 후 종료
    if (N == 0) {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    // N이 1이면 이익을 낼 수 없으므로 0을 출력 후 종료
    if (N == 1) {
        std::cout << 0 << "\n";
        return;
    }

    long long total_profit = 0;
    int max_price = v[N - 1]; // 가장 마지막 날의 가격을 초기 최고가로 설정

    // N-2번째 날부터 첫 번째 날까지 역순으로 순회
    for (int i = N - 2; i >= 0; --i) {
        if (v[i] < max_price) {
            // 현재 가격이 최고가보다 싸면 이익을 더함
            total_profit += max_price - v[i];
        }
        else {
            // 현재 가격이 더 비싸거나 같으면, 최고가를 갱신
            max_price = v[i];
        }
    }

    std::cout << total_profit << "\n";
}

int main() {
    // 입출력 속도 향상
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        // 각 테스트 케이스마다 solve 함수를 호출하여
        // 변수들이 서로에게 영향을 주지 않도록 함
        solve();
    }

    return 0;
}