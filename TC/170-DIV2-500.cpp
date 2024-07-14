// 10-14-2012 03:15:13+01:00	Submit	aajjbb	250	232.27
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

struct RecurrenceRelation {
	int moduloTen(vector <int> coef, vector <int> init, int N) {
		int i, j, M = init.size();
		int dp[N+1];

		REP(i, N+1) dp[i] = 0;

		REP(i, M) {
			dp[i] = init[i];
			if(dp[i] < 0) {
				dp[i] = ((10 - ((-dp[i]) % 10)) % 10);
			} else {
				dp[i] %= 10;
			}
		}

		for(int i = M; i <= N; i++) {
			REP(j, M) {
				dp[i] = (dp[i] + dp[i - j - 1] * coef[M - j - 1]);
				if(dp[i] < 0) {
					dp[i] = ((10 - ((-dp[i]) % 10)) % 10);
				} else {
					dp[i] %= 10;
				}
			}
		}

		return dp[N];
	}
};


// Powered by FileEdit
