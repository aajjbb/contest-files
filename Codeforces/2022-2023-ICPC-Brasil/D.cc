#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int main(void) {
    long long N, goal_x, goal_y;
    cin >> N >> goal_x >> goal_y;

    // (3, 1)
    // 8, 12, 6, 3
    // 8,  4, 2, 1

    // (9, 5)
    // 8, 4, 2,  9
    // 8, 4, 10, 5


    // (13, 13)
    // 8, 12,

    long long end_x = (1 << N);
    long long end_y = (1 << N);

    long long sx = (1 << (N - 1));
    long long sy = (1 << (N - 1));

    long long steps = 0;

    while (!(sx == goal_x && sy == goal_y)) {
        long long nx = 0;
        long long ny = 0;
        cerr << sx << " " << sy << "\n";

        if (sx < goal_x) {
            if ((sx + end_x) % 2 == 0) {
                nx = min(goal_x, (long long) (sx + end_x) / 2);
            } else {
                nx = min(goal_x, (long long) (sx + end_x - 1) / 2);
            }
        } else {
            if (sx % 2 == 0) {
                nx = max(goal_x, (long long) (sx / 2));
            } else {
                nx = max(goal_x, (long long) ((sx + 1) / 2));
            }
        }
        if (sy < goal_y) {
            if ((sy + end_y) % 2 == 0) {
                ny = min(goal_y, (long long) (sy + end_x) / 2);
            } else {
                ny = min(goal_y, (long long) (sy + end_x - 1) / 2);
            }
        } else {
            if (sy % 2 == 0) {
                ny = max(goal_y, (long long) (sy / 2));
            } else {
                ny = max(goal_y, (long long) ((sy + 1) / 2));
            }
        }
        sx = nx;
        sy = ny;
        steps += 1;
    }
    cerr << sx << " " << sy << "\n";

    cout << steps << "\n";

    return 0;
}
