// 01-06-2013 01:29:50+01:00	Submit	aajjbb	250	241.16
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

using namespace std;

typedef long long ll;
typedef long double ld;

struct DiagonalDisproportion {
	int getDisproportion(vector <string> matrix) {
		int i, j, ans = 0, N = (int) matrix.size();

		REP(i, N) REP(j, N) if(i == j) ans += matrix[i][j] - '0';

		REP(i, N) for(j = N - 1; j >= 0; j--) if(i == N - 1 - j) ans -= matrix[i][j] - '0';

		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit