#include <algorithm>
#include <vector>
#include <iostream>

typedef long long LL;
using namespace std;

int N,cnt,Mcnt,num;

LL x;

vector<LL> vCard;

int main() {

	cin >> N;

	for (int i = 0;i < N;i++) {
		cin >> x;
		vCard.push_back(x);
	}
	sort(vCard.begin(), vCard.end());

	for (int i = 1;i < N+1;i++) {
		if (vCard[i] != vCard[i - 1]) {
			num
		}
	}

}
