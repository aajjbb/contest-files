// 04-21-2013 18:25:40+01:00	Submit	aajjbb	1000	686.84
/* aajjbb */
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
#include <numeric>
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
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

int dp[60];

struct IncreasingSubsequences {
	long long count(vector <int> a) {
		a.push_back(INT_MAX/2);
		int i, j, N = a.size();
		memset(dp, 0, sizeof(dp));

		dp[0] = 1;

		for (i = 1; i < N; i++) {
			int least = 0;
			for (j = i - 1; j >= 0; j--) {
				if(a[j] >= least && a[i] > a[j]) {
					dp[i] += dp[j];
					least = a[j];
				}
			}
			if (dp[i] == 0) dp[i] += 1;
		}
		return dp[N-1];
	}
};

// Powered by FileEdit
