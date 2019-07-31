/*
28-07-2019 20:39:50
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

const int INF = INT_MAX/4;

int dp[60][10];

int func(int id, int mask, const vector<int>& R, const vector<int>& G, const vector<int>& B) {
	if (id == R.size()) {
		return (mask == 7) ? 0 : INF;
	} else {
		int& ans = dp[id][mask];
		
		if (ans == -1) {
			ans = INF;
			
			ans = min(ans, R[id] + G[id] + func(id + 1, mask | (1 << 2), R, G, B));
			ans = min(ans, R[id] + B[id] + func(id + 1, mask | (1 << 1), R, G, B));
			ans = min(ans, G[id] + B[id] + func(id + 1, mask | (1 << 0), R, G, B));
			
		}
		
		return ans;
	}
}

struct BallsSeparating {
	int minOperations(vector <int> red, vector <int> green, vector <int> blue) {
		memset(dp, -1, sizeof(dp));
				
		int ans = func(0, 0, red, green, blue);
		
		if (ans == INF) {
			ans = -1;
		}
		
		return ans;
	}
};


// Powered by FileEdit