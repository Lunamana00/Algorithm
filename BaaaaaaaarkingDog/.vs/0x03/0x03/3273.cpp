#include<iostream>
#include<vector>
#include <string>
using namespace std;

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	vector<int> v_1(2000000,0);
	int N,A,ans,count=0;

	cin >> N;
	vector<int> v_2(N,0);

	for (int i = 0; i < N; i++) {
		cin >> A;
		v_2[i] = A;
	}

	cin >> ans;

	for (auto x : v_2) {
		v_1[x] = 1;

		if(ans-x>=0 && ans != x){
			if (v_1[ans - x] == 1 && ans-x != x) {
				v_1[x] = 0;
				v_1[ans - x] = 0;
				count += 1;
			}
		}
	}
	cout << count;
}