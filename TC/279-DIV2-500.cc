// 06-23-2013 19:53:32+01:00	Submit	aajjbb	500	305.40
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

set<string> names;
set<string>::iterator it;

map<string, int> win, play;

struct TheTournament {
	string findLeader(vector <string> matches) {
		int i, N = matches.size();
		char buff_a[23], buff_b[23];

		for (i = 0; i < N; i++) {
			sscanf(matches[i].c_str(), "%s %*s %s", buff_a, buff_b);

			string a(buff_a), b (buff_b);

			win[a] += 1;

			play[a] += 1;
			play[b] += 1;

			names.insert(a);
			names.insert(b);
		}

		string ans;

		double best = -1001001010.0;

		for_each(it, names) {
			if (play[*it] == 0) continue;

			double now = (double) win[*it] / (double) play[*it];

			printf("%s %d %d\n", (*it).c_str(), win[*it], play[*it]);

			if (now > best) {
				best = now;
				ans = *it;
			}
		}

		return ans;
	}
};
<%:testing-code%>
// Powered by FileEdit