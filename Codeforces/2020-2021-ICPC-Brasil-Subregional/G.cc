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

const int MAXN = 10;

bool inside(int i, int j) {
    return min(i, j) >= 1 && max(i, j) <= MAXN;
}

const int START_VAL = 100;

int main(void) {
    int N;
    cin >> N;

    int cnt = START_VAL;
    int sum = START_VAL;

    for (int i = 0; i < N; i++) {
        int curr;
        cin >> curr;

        sum += curr;
        cnt = max(cnt, sum);
    }

    cout << cnt << "\n";

    return 0;
}
