// 12-17-2013 20:03:14+01:00	Submit	aajjbb	1000	770.97
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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class Piglets {
public:
	int choose(string);
};

bool func(string T, int p) {
	if (p == 0) {
		return (p + 1 < T.size() ? T[p + 1] != '-' : true);
	} else if (p == T.size() - 1) {
		return (p - 1 >= 0 ? T[p - 1] != '-' : true);
	} else {
		return T[p - 1] == '-' || T[p + 1] == '-';
	}
}

int Piglets::choose(string T) {
	int i;
	int j;
	int N = (int) T.size();

	int ans = 0;
	int ust = -1;

	if (T[0] == '-') return 0;
	if (T[N-1] == '-') return N - 1;

	if (T.find("-") == string::npos) {
		return -1;
	}

	for (i = 0; i < N; i++) if (T[i] == '-') {
		string cpy = T;
		int st = 0;

		for ( ; func(cpy, i); ) {
			st += 1;
			for (j = 0; j < N; j++) if (i != j && cpy[j] == '-') {
				cpy[j] = 'p';
				break;
			}
		}

		if (st > ust) {
			ust = st;
			ans = i;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
