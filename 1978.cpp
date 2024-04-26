#include <iostream>

int main() {

	int n, input,count =0,flag;

	std::cin >> n;

	for (int i = 0; i < n; ++i) {
		flag = 0;
		std::cin >> input;
		if (input > 1) {

			for (int s = 2; s < input; ++s) {

				if ((input % s)==false) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				count += 1;
			}
		}
	}

	std::cout << count;
}