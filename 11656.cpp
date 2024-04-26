#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {

	int count,t=0;

	std::string str;
	std::vector<std::string> v;

	std::cin >> str;
	
	for (int i = 0; i < str.size();++i) {

		v.push_back(str.substr(str.size()-i-1,i+1));

	}
	sort(v.begin(), v.end());
	for (auto x : v) {
		std::cout << x<<"\n";
	}
}
