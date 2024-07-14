// Submitted - 2016-09-05 05:31:36
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

class DivisibleSetDiv2 {
public:
	string isPossible(vector <int>);
};

string DivisibleSetDiv2::isPossible(vector <int> b) {
	int N = (int) b.size();
	vector<int> vs(N, 1);

	sort(b.begin(), b.end());

	for (int x = 0; x < 10000; x++) {
		int s = 0;

		for (int i = 0; i < N; i++) {
			s += vs[i];
		}

		bool fine = true;
		int wrong = -1;

		for (int i = 0; i < N; i++) {
			if (vs[i] * b[i] < s) {
				fine = false;
				wrong = i;
			}
		}
		if (fine) {
			return "Possible";
		}
		vs[wrong] += 1;
	}

	return "Impossible";
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!