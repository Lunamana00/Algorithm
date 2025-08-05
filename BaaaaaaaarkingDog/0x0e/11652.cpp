#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N;
	long long x; // ������ �ڷ����� long long�̹Ƿ� ���߾� �ݴϴ�.

	cin >> N;

	if (N == 0) { // ���� ó��: �Է��� ���� ���
		return 0;
	}

	vector<long long> v;
	for (int i = 0; i < N; i++) {
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	int cnt = 1;      // ���� ������ ���� Ƚ��
	int mxcnt = 1;    // �ִ� ���� Ƚ��
	long long ans = v[0]; // ����(���� ���� ���� ��), ù��° ���ҷ� �ʱ�ȭ

	for (int i = 1; i < N; i++) { // 2��° ���Һ��� ��ȸ
		if (v[i] == v[i - 1]) { // ���� ���ҿ� ���ٸ�
			cnt++;
		}
		else { // ���� ���ҿ� �ٸ��ٸ�
			if (cnt > mxcnt) { // ���ݱ����� ī��Ʈ�� �ִ� ī��Ʈ���� ũ��
				mxcnt = cnt;
				ans = v[i - 1]; // ������ ���� ���ҷ� ������Ʈ
			}
			cnt = 1; // ���ο� ���ڰ� ���۵Ǿ����Ƿ� ī��Ʈ�� 1�� ����
		}
	}

	// ������ ���� ��, ������ �׷쿡 ���� �˻縦 �ѹ� �� ����
	if (cnt > mxcnt) {
		ans = v[N - 1];
	}

	cout << ans;
}