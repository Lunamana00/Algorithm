#include <iostream>

using namespace std;

int n = 10;
int arr[1000001] = { 15, 25, 22, 357, 16, 23, -53, 12, 46, 3 };
int tmp[1000001]; // merge �Լ����� ����Ʈ 2���� ��ģ ����� �ӽ÷� �����ϰ� ���� ����

// mid = (st+en)/2��� �� �� arr[st:mid], arr[mid:en]�� �̹� ������ �Ǿ��ִ� ������ �� arr[st:mid]�� arr[mid:en]�� ��ģ��.
void merge(int st, int en) {
	int mid = (st + en) / 2;
	int lidx = st;
	int ridx = mid;

	for (int i = st; i < en; i++) {
		// 1. ���� �κ� �迭�� ������ ��츦 ���� ���� ó��
		if (lidx == mid) { // ���� �κ� �迭�� ������� ������ �κ� �迭�� ���� ���Ҹ� ������� ����
			tmp[i] = arr[ridx];
			ridx++;
		}
		else if (ridx == en) { // ������ �κ� �迭�� ������� ���� �κ� �迭�� ���� ���Ҹ� ������� ����
			tmp[i] = arr[lidx];
			lidx++;
		}
		// 2. �������� ������ ���� �� ���� ���� ���� (�� �κ� �迭 ��� ���Ұ� ���� ���)
		else if (arr[lidx] <= arr[ridx]) {
			tmp[i] = arr[lidx];
			lidx++;
		}
		else { // arr[lidx] > arr[ridx]
			tmp[i] = arr[ridx];
			ridx++;
		}
	}

	// �ӽ� �迭�� ����� ���� �迭�� ����
	for (int i = st; i < en; i++) {
		arr[i] = tmp[i];
	}
}

// arr[st:en]�� �����ϰ� �ʹ�.
void merge_sort(int st, int en) {
	if (st + 1 == en) return; // ���� 1�� ���
	int mid = (st + en) / 2;
	merge_sort(st, mid); // arr[st:mid]�� �����Ѵ�.
	merge_sort(mid, en); // arr[mid:en]�� �����Ѵ�.
	merge(st, en); // arr[st:mid]�� arr[mid:en]�� ��ģ��.
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	merge_sort(0, n);
	for (int i = 0; i < n; i++) cout << arr[i] << ' ';  // -53 3 12 15 16 22 23 25 46 357
}