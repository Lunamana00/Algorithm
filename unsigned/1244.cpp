#include <iostream>
#include <vector>

int main() {
	std::ios::sync_with_stdio(0), std::cin.tie(0);
	
	int switch_c, order_c, switch_cin;

	std::vector<int> v;
	std::cin >> switch_c;
	for (int i = 0; i < switch_c; ++i) {
		std::cin >> switch_cin;
		v.push_back(switch_cin);
	}
	
	int mf, add;

	std::cin >> order_c;
	for (int i = 0; i < order_c; ++i) {
		std::cin >> mf >> add;
		if(mf == 1){
			int add_point = add-1;
			while (add_point<v.size()) {
				v[add_point] += 1;
				add_point += add;
			}
		}
		else {
			add -= 1;
			v[add] += 1;
			int l_point = add - 1, r_point = add + 1;
			while (l_point >= 0 && r_point <= v.size() - 1) {
				if (v[l_point] % 2 == v[r_point] % 2) {
					v[l_point] += 1;
					v[r_point] += 1;
					l_point -= 1;
					r_point += 1;
				}
				else {
					break;
				}
			}
		}
	}
	int count = 0;
	for (auto x : v) {
		std::cout << x%2 << " ";
		count += 1;
		if (count == 20) {
			std::cout << "\n";
			count = 0;
		}
	}
}