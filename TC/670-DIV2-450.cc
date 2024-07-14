// Submitted - 2015-10-13 19:57:29
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

class Drbalance {
public:
	int lesscng(string, int);
};

int check(string s, int len) {
	int ans = 0;
	int curr = 0;

	for (int i = 0; i < len; i++) {
		if (s[i] == '+') {
			curr += 1;
		} else {
			curr -= 1;
		}
		if (curr < 0) ans += 1;
	}

	return ans;
}

int Drbalance::lesscng(string s, int k) {
	int ans = 0;
	int N = (int) s.size();
	int diff = check(s, N);


	while (diff > k) {
		for (int i = 0; i < N; i++) {
			if (s[i] == '-') {
				s[i] = '+';
				ans += 1;
				break;
			}
		}
		diff = check(s, N);
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!