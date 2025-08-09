#include <iostream>
#include <vector>
#include <numeric> // iota ��� (�ʼ��� �ƴ�)

void solve() {
    int N;
    std::cin >> N;

    // N�� 0�̸� �ƹ��͵� �Է¹��� �ʰ� 0�� ��� �� ����
    if (N == 0) {
        std::cout << 0 << "\n";
        return;
    }

    std::vector<int> v(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    // N�� 1�̸� ������ �� �� �����Ƿ� 0�� ��� �� ����
    if (N == 1) {
        std::cout << 0 << "\n";
        return;
    }

    long long total_profit = 0;
    int max_price = v[N - 1]; // ���� ������ ���� ������ �ʱ� �ְ��� ����

    // N-2��° ������ ù ��° ������ �������� ��ȸ
    for (int i = N - 2; i >= 0; --i) {
        if (v[i] < max_price) {
            // ���� ������ �ְ����� �θ� ������ ����
            total_profit += max_price - v[i];
        }
        else {
            // ���� ������ �� ��ΰų� ������, �ְ��� ����
            max_price = v[i];
        }
    }

    std::cout << total_profit << "\n";
}

int main() {
    // ����� �ӵ� ���
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int T;
    std::cin >> T;
    while (T--) {
        // �� �׽�Ʈ ���̽����� solve �Լ��� ȣ���Ͽ�
        // �������� ���ο��� ������ ���� �ʵ��� ��
        solve();
    }

    return 0;
}