#include<iostream>

int main() {

	int a;

	std::cin >> a;

	for (int i=0; i < a; i++) {
		for (int s=0; s <(a - i-1); s++) {
			std::cout << " ";
		}
		for (int p=0; p < i+1; p++) {
			std::cout << "*";
		}
		std::cout << "\n";
	}
}