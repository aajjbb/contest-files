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

int A, B;

int main(void) {
	for ( ; cin >> A >> B; ) {
		for (int i = 1; ; i++) {
			int p = i * A;
			int q = i * B;

			if (p + B <= q) {
				cout << i << endl;
				break;
			}
		}
	}
    return 0;
}
