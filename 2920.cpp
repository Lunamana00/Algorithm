#include <iostream>
#include <vector>
int main() {

	int k;

	std::vector<int> v_a, v_d, v_t;

	v_a = { 1,2,3,4,5,6,7,8 };
	v_d = { 8,7,6,5,4,3,2,1 };

	for (int i=0; i < 8; i++) {
		std::cin >> k;
		v_t.push_back(k);
	}

	if (v_t == v_a) {
		std::cout << "ascending";
	}
	else if (v_t == v_d) {
		std::cout << "descending";
	}
	else {
		std::cout << "mixed";
	}
}