#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> plusV;   // 1보다 큰 양수
	vector<int> minusV;  // 음수
	long long ans = 0;   // 최종 합계 (결과가 클 수 있으므로 long long)
	int zero_count = 0;

	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		if (x > 1) {
			plusV.push_back(x);
		}
		else if (x == 1) {
			ans += 1; // 1은 곱하는 것보다 더하는 것이 항상 이득이므로 바로 더함
		}
		else if (x < 0) {
			minusV.push_back(x);
		}
		else { // x == 0
			zero_count++;
		}
	}

	// 1. 양수 처리 (큰 수부터 짝지어 곱하기)
	sort(plusV.rbegin(), plusV.rend()); // 내림차순 정렬 (큰 수부터)
	for (int i = 0; i < plusV.size(); i += 2) {
		if (i + 1 < plusV.size()) { // 짝이 있으면 곱하기
			ans += (long long)plusV[i] * plusV[i + 1];
		}
		else { // 짝이 없으면 그냥 더하기
			ans += plusV[i];
		}
	}

	// 2. 음수 처리 (작은 수부터 짝지어 곱하기)
	sort(minusV.begin(), minusV.end()); // 오름차순 정렬 (절댓값이 큰 수부터)
	for (int i = 0; i < minusV.size(); i += 2) {
		if (i + 1 < minusV.size()) { // 짝이 있으면 곱하기
			ans += (long long)minusV[i] * minusV[i + 1];
		}
		else { // 짝이 없고, 0도 없으면 어쩔 수 없이 더하기
			if (zero_count == 0) {
				ans += minusV[i];
			}
			// 짝이 없고 0이 있으면, 0과 곱해서 없애버림 (아무것도 더하지 않음)
		}
	}

	cout << ans << endl;

	return 0;
}