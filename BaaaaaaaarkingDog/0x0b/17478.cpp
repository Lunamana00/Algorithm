#include <iostream>
#include <string>

using namespace std;

void func(int N, int M) {
	string underbar = string(4 * (M - N), '_');

	cout << underbar << "\"����Լ��� ������?\"\n";

	if (N == 0) {
		cout << underbar << "\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n";
	}
	else {
		cout << underbar << "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n";
		cout << underbar << "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n";
		cout << underbar << "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n";
		func(N - 1, M);
	}

	cout << underbar << "��� �亯�Ͽ���.\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	cout << "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n";
	func(N, N);
}
