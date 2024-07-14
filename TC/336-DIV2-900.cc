// 12-09-2013 18:25:05+01:00	Submit	aajjbb	900	761.26
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

class MostLikely {
public:
	int likelyRank(vector <int>, int, int);
};

int MostLikely::likelyRank(vector <int> sc, int low, int high) {
	int i;
	int best = 0;
	int rank = 0;

	sc.push_back(-1); sc.push_back(high + 1);

	sort(sc.rbegin(), sc.rend());

	int N = (int) sc.size();

	for (i = 0; i < N - 1; i++) {
		int bound_l = max(low, sc[i + 1]);
		int bound_r = min(high, sc[i] - 1);

		if (bound_r >= bound_l) {
			int ot = bound_r - bound_l + 1;

			if (ot > best) {
				best = ot;
				rank = i + 1;
			} else if (ot == best) {
				rank = -1;
			}
		}
	}

	return rank;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!