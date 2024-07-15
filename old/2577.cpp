#include <iostream>
#include <string>
#include <vector>
int main() {

	int mul_num=1,n;
	std::string str;
	std::vector<int> v(10,0);

	while (std::cin >> n) {

		mul_num *= n;

	}

	str = std::to_string(mul_num);
	for (auto x : str) {
		v[static_cast<int>(x)-'0'] += 1;
	}

	for (auto x : v) {
		std::cout << x<<"\n";
	}


}