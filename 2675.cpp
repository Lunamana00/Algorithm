#include <iostream>
#include <string>
int main() {

	int n,n_2;
	std::string str;

	std::cin >> n;
	
	for (int i = 0; i < n; ++i) {
		
		std::cin >> n_2;
		std::cin >> str;

		for (auto x : str) {
			for (int s = 0; s < n_2; ++s) {
				std::cout << x;

			}
		}
		std::cout << "\n";
	}

}