// 2013-11-20T04:24:50+01:00
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
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long int64;

struct PaternityTest {
	vector <int> possibleFathers(string child, string mother, vector <string> men) {
		int i, j, temp;
		vector<int> ret;
		string::iterator it;

		REP(i, sz(men)) {
			temp = 0;
			REP(j, sz(men[i])) {
				if(child[j] != mother[j] && child[j] != men[i][j]) { temp = 0; break; }
				if(child[j] == men[i][j]) { temp++; }
			}
			if(temp >= sz(child) / 2) ret.pb(i);
		}
		return ret;
	}
};


// Powered by FileEdit