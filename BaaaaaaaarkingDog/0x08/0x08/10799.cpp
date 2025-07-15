#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>


int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    std::stack<char> st1;
    std::string str1;

    std::vector<int> lineStart;
    std::vector<std::pair<int, int>> linePair;
    std::vector<int> lazor(100000);
    std::vector<int> lazor_iter;
    std::cin >> str1;

    int count=0;
    
    for (int i = 1; i < str1.size(); i++) {

        if (str1[i] == ')' && str1[i - 1] == '(') {
            lazor[i]=1;
            lazor[i-1] = 1;
            lazor_iter.push_back(i);
        }

        
    }

    for (int i = 0; i < str1.size(); i++) {

        if (str1[i] == '(' && lazor[i] != 1) {
            lineStart.push_back(i);
            continue;
        }

        if (str1[i] == ')'&&lazor[i] != 1) {
            linePair.push_back({ lineStart[lineStart.size() - 1],i });
            lineStart.pop_back();
            continue;
        }
    }

    for (auto x : linePair) {
        count++;
        for (auto l : lazor_iter) {
            if (l > x.first && l < x.second) {
                count++;
            }
        }
    }
    std::cout << count;
}
