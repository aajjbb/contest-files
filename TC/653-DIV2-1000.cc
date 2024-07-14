// Submitted - 2015-03-22 03:43:14
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

class SingingEasy {
public:
	int solve(vector <int>);
};

const int INF = 10001010;
const int MAXN = 2002;
int N;
vector<int> p;
map<int, map<int, int> > dp[MAXN];
map<int, map<int, bool> >mk[MAXN];

int func(int pos, int la, int lb) {
	if (pos >= N) {
		return 0;
	} else {
		int& ans = dp[pos][la][lb];

		if (!mk[pos][la][lb]) {
			mk[pos][la][la] = true;
			ans = INF;

			int pa = la == 0 ? p[pos] : p[la];
			int pb = lb == 0 ? p[pos] : p[lb];

			chmin(ans, abs(pa - p[pos]) + func(pos + 1, pos, lb));
			chmin(ans, abs(pb - p[pos]) + func(pos + 1, la, pos));
		}

		return ans;
	}
}

int SingingEasy::solve(vector <int> pitch) {
	p.push_back(0);

	for (int i = 0; i < (int) pitch.size(); i++) {
		p.push_back(pitch[i]);
	}

	N = (int) p.size();

	return func(1, 0, 0);
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!