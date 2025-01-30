#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <list>
#include <stack>

using namespace std;

const int MX = 1000005;

int dat[2 * MX + 1];
int head = MX, tail = MX;

void push_front(int x) {
    dat[head] = x;
    head--;
}

void push_back(int x){
    dat[tail] = x;
    tail++;
}

void pop_front() {
    head++;
}

void pop_back() {
    tail--;
}

int front() {
    return dat[head];
}

int back() {
    return dat[tail];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
}