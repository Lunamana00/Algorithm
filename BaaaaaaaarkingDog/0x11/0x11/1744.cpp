#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> plusV;   // 1���� ū ���
	vector<int> minusV;  // ����
	long long ans = 0;   // ���� �հ� (����� Ŭ �� �����Ƿ� long long)
	int zero_count = 0;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x > 1) {
			plusV.push_back(x);
		}
		else if (x == 1) {
			ans += 1; // 1�� ���ϴ� �ͺ��� ���ϴ� ���� �׻� �̵��̹Ƿ� �ٷ� ����
		}
		else if (x < 0) {
			minusV.push_back(x);
		}
		else { // x == 0
			zero_count++;
		}
	}

	// 1. ��� ó�� (ū ������ ¦���� ���ϱ�)
	sort(plusV.rbegin(), plusV.rend()); // �������� ���� (ū ������)
	for (int i = 0; i < plusV.size(); i += 2) {
		if (i + 1 < plusV.size()) { // ¦�� ������ ���ϱ�
			ans += (long long)plusV[i] * plusV[i + 1];
		}
		else { // ¦�� ������ �׳� ���ϱ�
			ans += plusV[i];
		}
	}

	// 2. ���� ó�� (���� ������ ¦���� ���ϱ�)
	sort(minusV.begin(), minusV.end()); // �������� ���� (������ ū ������)
	for (int i = 0; i < minusV.size(); i += 2) {
		if (i + 1 < minusV.size()) { // ¦�� ������ ���ϱ�
			ans += (long long)minusV[i] * minusV[i + 1];
		}
		else { // ¦�� ����, 0�� ������ ��¿ �� ���� ���ϱ�
			if (zero_count == 0) {
				ans += minusV[i];
			}
			// ¦�� ���� 0�� ������, 0�� ���ؼ� ���ֹ��� (�ƹ��͵� ������ ����)
		}
	}

	cout << ans << endl;

	return 0;
}