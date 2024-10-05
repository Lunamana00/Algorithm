#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, M,x;
	std::cin >> N >> M;
	std::vector<int>v;

	for(int s=0; s<N;++s){
		double sum = 0;
		for (int i = 0; i < N; ++i) {
			std::cin >> x;
			sum += x;
			v.push_back(sum);
		}
	}


	for (int i = 0; i < M; ++i) {
		int x1, y1, x2, y2;
		double sum = 0;
		std::cin >> y1>> x1>> y2>> x2;
		
		for (int s = 0; s <= (y2 - y1); ++s) {

			if (x1 != 1) {
				sum += v[(y1 + s - 1) * N + x2 -1] - v[(y1 + s - 1) * N + x1 - 2];
			}
			else {
				sum += v[(y1 + s - 1) * N + x2 - 1];
			}
			
		}
		std::cout << sum<<"\n";
	}
}