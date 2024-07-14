// Incomplete solution.
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

const int MAXN = 1009;
int dp[MAXN][MAXN], m[MAXN][MAXN];

int func(int x, int y, int N) {
	int i, j, ans = 0;

	for (i = 0; i < N; i++) for (j = 0; j < N; j++) dp[i][j] = 0;

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) if (m[i][j] == x || m[i][j] == y) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
			} else if (i >= 1 && j >= 1) {
				dp[i][j] = 1 + max(dp[i][j], max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1])));
				ans = max(ans, dp[i][j] * dp[i][j]);
			}
		}
	}

	return ans;
}

struct GrandpaField {
	int getArea(int N, vector <string> changes) {
		int i, j, k, M = changes.size();

		for (i = 0; i < N; i++) for (j = 0; j < N; j++) m[i][j] = 0;

		for (i = 0; i < M; i++) {
			int X, Y, L, F;
			sscanf(changes[i].c_str(), "%d %d %d %d", &X, &Y, &L, &F);
			for (j = X; j < X + L; j++) {
				for (k = Y; k < Y + L; k++) {
					m[j][k] = F;
				}
			}
		}

		int ans = 0;

		for (i = 1; i <= 7; i++) for (j = i + 1; j <= 7; j++) ans = max(ans, func(i, j, N));

		return ans;
	}
};
<%:testing-code%>
// Powered by FileEdit