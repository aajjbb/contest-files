// 2012-11-26T00:58:06+01:00
#line 52 "Justifier.cpp"
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

struct Justifier {
	vector <string> justify(vector <string> textIn) {
		int i, N = textIn.size();
		vector<string> ans(N, "");

		int thersold = 0;
		REP(i, N) thersold = max(thersold, (int) textIn[i].size());

		REP(i, N) {
			while(ans[i].size() + textIn[i].size() != thersold) {
				ans[i] += " ";
			}
			ans[i] += textIn[i];
		}

		return ans;
	}
};


// Powered by FileEdit
