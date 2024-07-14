// 12-11-2012 23:48:07+01:00	Submit	aajjbb	500	489.32
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

int cost(string page) {
	int i, countD = 0;
	REP(i, page.size()) if(page[i] == 'D') countD += 1;
	return countD == 0 ? 0 : (min(countD + 1, 2 + (int) page.size() - countD));
}

struct InboxCleanup {
	int fewestClicks(string messages, int low, int high) {
		int j, msg, ans = INT_MAX, N = messages.size();
		FOR(msg, low, high+1) {
			int now = 0;
			for(j = 0; j < N; j += msg) {
				if(j != 0) now += 1;
				now += cost(messages.substr(j, msg));
			}
			ans = min(ans, now);
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit