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
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(N);
    int open_values = 0;

    for (int i = 0; i < N; i++) {
        cin >> A[i];

        if (A[i] == 0) {
            open_values += 1;
        }
    }

    for (int goal = 1; goal <= M; goal++) {
        int se = get_smaller_or_equal(A, goal);
        int gt = get_greater_than(A, goal);


    }

    return 0;
}
