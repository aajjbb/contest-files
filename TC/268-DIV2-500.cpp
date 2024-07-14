// 10-14-2013 21:30:21+01:00	Submit	aajjbb	500	150.00
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

struct CmpdWords {
	int ambiguous(vector <string> dictionary) {
		int i, j, ans = 0, N = dictionary.size();

		map<string, int> mp;
		map<string, int>::iterator it;

		REP(i, N) mp[dictionary[i]] = 1;

		REP(i, N) REP(j, N) if(i != j) {
			mp[dictionary[i]+dictionary[j]] += 1;
		}

		for(it = mp.begin(); it != mp.end(); it++) {
			if(it->second > 1) ans += 1;
		}

		return ans;
	}
};


// Powered by FileEdit