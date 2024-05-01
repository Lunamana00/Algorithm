#include <iostream>

int main() {

	int n;
	double k, sum=0, max = 0;
	std::cin >> n;
	
	for (int i = 0; i < n; ++i) {

		std::cin >> k;
		sum += k;
		if (max < k) max = k;
	}
	std::cout << (100*sum / max)/n;
}