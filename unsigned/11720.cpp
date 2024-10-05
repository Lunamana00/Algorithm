#include <iostream>
#include <string>
int main() {

	int n,sum = 0;
	char k;
	
	std::cin >> n;

	for (int i = 0; i < n; ++i) {

		std::cin >> k;
		sum += static_cast<int>(k-'0');

	}
	std::cout << sum;
}