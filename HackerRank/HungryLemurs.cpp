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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

int N, K;

int main(void) {
	cin >> N >> K;

	int ans = K;
	
	for (int i = 1; i <= 2 * K; i++) {
		int curr = abs(K - i);

		curr += min(N % i, abs(i - (N % i)));

		chmin(ans, curr);
	}

	cout << ans << "\n";
	return 0;
}
