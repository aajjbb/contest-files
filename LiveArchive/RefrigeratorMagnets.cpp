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

string S;
int cnt[27];

int main(void) {
	for ( ; getline(cin, S) && S != "END"; ) {
		memset(cnt, 0, sizeof(cnt));
		bool ok = true;
		for (int i = 0; ok && i < (int) S.size(); i++) {
			if (S[i] == ' ') continue;
			cnt[S[i] - 'A'] += 1;
			if (cnt[S[i] - 'A'] > 1) {
				ok = false;
			}
		}
		if (ok) {
			cout << S << "\n";
		}
	}
    return 0;
}
