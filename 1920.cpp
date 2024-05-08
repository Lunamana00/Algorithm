#include <iostream>
#include <algorithm>
#include <vector>
#define SETTING std::ios::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0)
/*
int find_mid(std::vector<int> v, int x,int mid) {
	
	int r_v;
	if (x > v[v.size()-1] || x < v[0]) {
		return 0;
	}

	if (v[mid] == x) {
		r_v = 1;
	}
	else if (mid==0 || mid==v.size()-1) {
		r_v = 0;
	}
	else if (v[mid] > x) {
		r_v = find_mid(v, x, (mid / 2));
		
	}
	else if (v[mid] < x) {
		r_v = find_mid(v, x, ((v.size() + mid) / 2));
	}
	
	return r_v;
}
*/
int main() {
	SETTING;
	int N,x,mid;
	std::vector<int> v;

	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	
	std::cin >> N;
	for (int i = 0; i < N; ++i) {
		std::cin >> x;
		mid = v.size() / 2;
		while (true) {
			if (v[mid] == x) {
				std::cout << 1;
				break;
			}
			else if (x > v[v.size() - 1] || x < v[0]) {
				std::cout << 0;
				break;
			}
			else if ((v[mid] < x && x < v[mid + 1]) || (v[mid - 1] < x && x < v[mid])) {
				std::cout << 0;
				break;
			}else if (v[mid] > x) {
				mid = mid / 2;
			}
			else if (v[mid] < x) {
				mid = (v.size() + mid) / 2;
			}
		}
	}
}