// 11-28-2012 21:38:37+01:00	Submit	aajjbb	250	239.08
/*aajjbb*/
#line 62 "InsertionSortCount.cpp"
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

struct InsertionSortCount {
	int countMoves(vector <int> A) {
		int i, ans = 0;

		FOR(i, 1, A.size()) {
			int a = A[i], b = i;
			while(b > 0 && A[b - 1] > a) {
				A[b] = A[b - 1];
				b--;
				ans += 1;
			}
			A[b] = a;
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit