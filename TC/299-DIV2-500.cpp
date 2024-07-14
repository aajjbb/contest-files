// 11-24-2012 19:52:24+01:00	Submit	aajjbb	500	300.13
/*aajjbb*/
#line 83 "Projections.cpp"
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

struct Projections {
	vector <int> count(string front, string right) {
		vector<int> ans(2);
		ans[0] = simul_min(front, right);
		ans[1] = simul_max(front, right);
		return ans;
	}
	int simul_min(string& front, string& right) {
		int r = 0, c = 0;
		REP(i, right.size()) if(right[i] == 'x') r += 1;
		REP(i, front.size()) if(front[i] == 'x') c += 1;
		return max(r, c);
	}
	int simul_max(string& front, string& right) {
		int ans = 0;

		REP(i, right.size()) {
			REP(j, front.size()) {
				if(right[i] == 'x' && front[j] == 'x') ans += 1;
			}
		}

		return ans;
	}
};


// Powered by FileEdit
