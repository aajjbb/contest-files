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

const int MAXN = 200005;

int N, M, K;
int A[MAXN], B[MAXN];
long long sumA[MAXN], sumB[MAXN];

int main(void) {
    cin >> N >> M >> K;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        sumA[i] = sumA[i - 1] + A[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> B[i];

        sumB[i] = sumB[i - 1] + B[i];
    }

    int ans = 0;

    for (int i = 0; i <= N; i++) {
        int l = 0, h = M;

        while (l <= h) {
            int m = (l + h) / 2;

            if (sumA[i] + sumB[m] <= K) {
                ans = max(ans, i + m);
                l = m + 1;
            } else {
                h = m - 1;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
