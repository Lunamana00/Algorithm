#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 날짜를 정수로 변환하는 더 안정적인 방법
int date_to_int(int month, int day) {
    int month_days[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int total_days = 0;
    for (int i = 1; i < month; ++i) {
        total_days += month_days[i];
    }
    total_days += day;
    return total_days;
}

struct Flower {
    int start_day;
    int end_day;
};

// 정렬을 위한 비교 함수
bool compareFlowers(const Flower& a, const Flower& b) {
    if (a.start_day != b.start_day) {
        return a.start_day < b.start_day;
    }
    return a.end_day > b.end_day;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<Flower> flowers;
    for (int i = 0; i < N; ++i) {
        int sm, sd, em, ed;
        cin >> sm >> sd >> em >> ed;
        flowers.push_back({ date_to_int(sm, sd), date_to_int(em, ed) });
    }

    sort(flowers.begin(), flowers.end(), compareFlowers);

    int count = 0;
    int current_day = date_to_int(3, 1); // 3월 1일부터 시작
    int target_day = date_to_int(11, 30);
    int idx = 0;

    while (current_day <= target_day) {
        int max_end_day = 0;

        // current_day 이전에 피는 꽃들 중 가장 늦게 지는 꽃 찾기
        while (idx < N && flowers[idx].start_day <= current_day) {
            max_end_day = max(max_end_day, flowers[idx].end_day);
            idx++;
        }

        if (max_end_day == 0 || max_end_day <= current_day) {
            count = 0;
            break;
        }

        count++;
        current_day = max_end_day;
    }

    cout << count << endl;

    return 0;
}