// 2013-03-01T19:49:58+00:01
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

struct LeaguePicks {
	vector <int> returnPicks(int position, int friends, int picks) {
		position -= 1;
		priority_queue<int> q;

		for(int i = 1; i <= picks; i++) q.push(-i);

		vector<int> memo[friends];

		int pos = 0;
		bool asc = true;

		while(!q.empty()) {
			int now = -q.top(); q.pop();

			memo[pos].push_back(now);

			if(asc) {
				pos += 1;
			} else {
				pos -= 1;
			}

			if(pos == friends) {
				asc = false; pos -= 1;
			} else if(pos == -1) {
				asc = true; pos += 1;
			}
		}

		sort(memo[position].begin(), memo[position].end());

		return memo[position];
	}
};

<%:testing-code%>
// Powered by FileEdit