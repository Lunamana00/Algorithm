#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	long N, M,sum=0,x,count=0;
	std::cin >> N >> M;
	std::vector<long> v;
	std::vector<long> c(M);
	

	for (int i = 0; i < N; ++i) {
		std::cin >> x;
		sum += x;
		v.push_back(sum%M);
	}
	
	for (auto x : v) {
		if (x == 0) {
			count += 1;
		}
		c[x] += 1;
	}
	for (auto x : c) {
		if (x > 1) {
			count += x * (x - 1) / 2;
		}
	}
	std::cout << count;
}