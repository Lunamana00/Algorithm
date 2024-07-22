#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int stack[1000000];
int pos = 0;

void push(int x) {

    stack[pos] = x;
    pos++;

}

void pop() {
    if (pos == 0) {
        cout << -1;
    }
    else {
        cout << stack[pos - 1];
        pos--;
    }
    

}

void size() {

    cout << pos;

}


void empty() {

    if (pos == 0) {
        cout << 1;
    }
    else {
        cout << 0;
    }

}

void top() {

    if (pos == 0) {
        cout << -1;
    }
    else {
        cout << stack[pos - 1];
    }
   

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    int N;
    cin >> N;
    string s;

    for (int i = 0; i < N; i++) {
        cin >> s;
        if (s == "push") {
            int x;
            cin >> x;
            push(x);
        }
        else if (s == "pop") {
            pop();
            cout << '\n';
        }
        else if (s == "size") {
            size();
            cout << '\n';
        }
        else if (s == "empty") {
            empty();
            cout << '\n';
        }
        else if (s == "top") {
            top();
            cout << '\n';
        }
    }

}
