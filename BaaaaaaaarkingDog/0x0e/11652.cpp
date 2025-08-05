#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long x; // 원소의 자료형이 long long이므로 맞추어 줍니다.

	cin >> N;

	if (N == 0) { // 예외 처리: 입력이 없는 경우
		return 0;
	}

	vector<long long> v;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int cnt = 1;      // 현재 숫자의 등장 횟수
	int mxcnt = 1;    // 최대 등장 횟수
	long long ans = v[0]; // 정답(가장 많이 나온 수), 첫번째 원소로 초기화

	for (int i = 1; i < N; i++) { // 2번째 원소부터 순회
		if (v[i] == v[i - 1]) { // 이전 원소와 같다면
			cnt++;
		}
		else { // 이전 원소와 다르다면
			if (cnt > mxcnt) { // 지금까지의 카운트가 최대 카운트보다 크면
				mxcnt = cnt;
				ans = v[i - 1]; // 정답을 이전 원소로 업데이트
			}
			cnt = 1; // 새로운 숫자가 시작되었으므로 카운트를 1로 리셋
		}
	}

	// 루프가 끝난 후, 마지막 그룹에 대한 검사를 한번 더 수행
	if (cnt > mxcnt) {
		ans = v[N - 1];
	}

	cout << ans;
}