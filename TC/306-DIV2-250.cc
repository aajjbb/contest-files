// 12-07-2013 20:34:44+01:00	Submit	aajjbb	250	171.17
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

class SortMachine {
public:

	int countMoves(vector <int>);
};

int SortMachine::countMoves(vector <int> a) {
	int i;
	int N = (int) a.size();
	int ans = 0, pos = 0;

	vector<int> cp(a.begin(), a.end());

	sort(cp.begin(), cp.end());

	for (i = 0; i < N; i++)	{
		int cnt = 0;
		for ( ; cp[pos] == a[i]; i++) {
			pos++;
			cnt++;
		}
		chmax(ans, cnt);
	}

	return max(0, N - ans);
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!