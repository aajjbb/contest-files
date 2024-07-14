// 2013-03-27T20:52:12+01:00
/*
aajjbb
*/
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

map<ll, int> dp;

int rec(ll cost) {
	if(cost == 0LL) return 0;
	if(dp.count(cost)) return dp[cost];

	ll min_a = 1, min_b = 25;

	while(min_a * 10 <= cost) {
		min_a *= 10;
	}
	while(min_b * 100 <= cost) {
		min_b *= 100;
	}

	dp[cost] = rec(cost - min_a) + 1;
	if(min_b <= cost) {
		dp[cost] = min(dp[cost], rec(cost - min_b) + 1);
	}
	return dp[cost];
}

struct AnotherCoinProblem {
	int minimumCoins(long long cost) {
		return rec(cost);
	}
};
<%:testing-code%>
// Powered by FileEdit