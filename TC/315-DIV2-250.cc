// 09-06-2012 23:45:05+01:00	Submit	aajjbb	250	248.74
/*
 aajjbb
*/
#line 69 "RosePetals.cpp"
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

struct RosePetals {
 	int getScore(vector <int> dice) {
 		map<int, int> mp;
 		mp[3] = 2;
 		mp[5] = 4;
 		int i, ans = 0;
 		REP(i, dice.size()) ans += mp[dice[i]];
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit