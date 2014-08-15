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
typedef unsigned uint;

const int MAXN = 10010;

int N;
int P[MAXN];

int main(void) {
	for ( ; scanf("%d", &N) && N != -1; ) {
		int S = 0;
		int ans = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d", &P[i]);
			S += P[i];
		}
		if (S % N == 0) {
			S /= N;		
			for (int i = 0; i < N; i++) {
				ans += max(0, P[i] - S);
			}
		} else {
			ans = -1;
		}
		printf("%d\n", ans);
	}
    return 0;
}
