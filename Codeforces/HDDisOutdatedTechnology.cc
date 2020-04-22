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

pair<int, int> get_partition(int p, int q, const int n) {
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i * p + j * q > n) {
                break;
            }
            if (i * p + j * q == n) {
                return make_pair(i, j);
            }
        }
    }
    return make_pair(-1, -1);
}

int main(void) {
    int N;

    cin >> N;

    vector<int> P(N);
    vector<int> pos(N);

    for (int i = 0; i < N; i++) {
        cin >> P[i];
        
        P[i] -= 1;
        pos[P[i]] = i;
    }

    long long ans = 0;

    for (int i = 1; i < N; i++) {
        ans += abs(pos[i - 1] - pos[i]);
    }

    cout << ans << "\n";

    return 0;
}
