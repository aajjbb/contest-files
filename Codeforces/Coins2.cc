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
    int N, A = 0, B = 0;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) {
            A += 1;
        } else {
            B += 1;
        }
    }

    cout << min(A, B) << endl;

    return 0;
}
