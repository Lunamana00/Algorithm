#include <iostream>

int main() {

	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);


	int n, m,*a,*sum_a,k;
	
	std::cin >> n >> m;

	sum_a = new int[n];
	a = new int[n];

	for (int i = 0; i < n; ++i) {

		std::cin >> k;
		a[i] = k;
	}
	
	sum_a[0] = a[0];

	for (int i = 1; i < n; ++i) {

		sum_a[i] = sum_a[i - 1] + a[i];

	}

	for (int i = 0; i < m; i++) {

		int x, y;
		std::cin >> x >> y;
		if (x == y) {
			std::cout << a[y - 1] << "\n";
		}
		else if(x != 1){
			std::cout << sum_a[y-1] - sum_a[x - 2] << "\n";
		}
		else {
			std::cout << sum_a[y - 1]<<"\n";
		}
	}
}