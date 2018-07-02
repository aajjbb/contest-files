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

int N;

int main(void) {
    cin >> N;

    vector<bool> done(N, false);
    vector<string> A(N), B(N);
    int ans = 0;

    map<string, int> cnt;
    
    for (int i = 0; i < N; i++) {
		cin >> A[i];

        cnt[A[i]] += 1;
    }
    for (int i = 0; i < N; i++) {
		cin >> B[i];

        if (cnt[B[i]]) {
			cnt[B[i]] -= 1;
        } else {
			ans += 1;
        }
    }

    cout << ans << endl;

    return 0;
}
