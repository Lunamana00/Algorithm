#include <iostream>
#include <vector>

int main() {

	double a,b,v,n;
	std::cin >> a>> b>> v;

	if (v <= a) {
		std::cout << 1;
	}
	else {
		n = (v - b) / (a - b);
		if (n == static_cast<int>(n)) {
			std::cout << static_cast<int>(n);
		}
		else {
			std::cout << static_cast<int>(n) +1;
		}
			
	}
}