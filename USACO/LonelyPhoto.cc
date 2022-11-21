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

char oppo(char c) {
    if (c == 'G') return 'H';
    return 'G';
}

int main(void) {
    int N;
    string S;

    cin >> N >> S;

    long long ans = 0;

    for (int i = 0; i < N; i++) {
        long long exp_l = 0;
        long long exp_r = 0;

        if (i - 1 >= 0 && S[i - 1] != S[i]) {
            exp_l += 1;
            for (int k = i - 2; k >= 0 && S[k] == S[i - 1]; k--) {
                exp_l += 1;
            }
        }
        if (i + 1 < N && S[i + 1] != S[i]) {
            exp_r += 1;
            for (int k = i + 2; k < N && S[k] == S[i + 1]; k++) {
                exp_r += 1;
            }
        }

        //cout << ans << " " << exp_l * exp_r << " " << max(exp_l - 1, 0LL) + max(exp_r - 1, 0LL) << " ";

        ans += exp_l * exp_r;
        ans += max(exp_l - 1, 0LL) + max(exp_r - 1, 0LL);
     }

    cout << ans << "\n";

    return 0;
}
