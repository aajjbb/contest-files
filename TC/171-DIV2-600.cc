// 04-07-2013 22:54:32+01:00	Submit	aajjbb	600	180.00
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

const int MAXN = 30;
int cnt[MAXN] = {0}, sum[MAXN] = {0}, has_six[MAXN] = {0}, shold = -1;
vector<int> mem[MAXN];

int func(void) {
	int i, curr = INT_MAX, ind = 0, all = 0;
	set<int> items;
	for(i = 0; i < 27; i++) {
		if(cnt[i] >= 5) {
			if(sum[i] < curr) {
				curr = sum[i];
				ind = i;
			}
			items.insert(sum[i]);
			all += 1;
		}
	}
	if(items.size() != all) {
		return -1;
	} else return ind;
}

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.first == b.first) {
		if(mem[a.second].size() > 5 && mem[b.second].size() > 5) {
			return mem[a.second][5] < mem[b.second][5];
		} else {
			if(mem[a.second].size() != mem[b.second].size() > 5) return mem[a.second].size() > mem[b.second].size();
			else return a.second < b.second;
		}
	} else {
		return a.first < b.first;
	}
}

struct CrossCountry {
	string scoreMeet(int numTeams, string finishOrder) {
		string ans = "";
		int i, N = finishOrder.size();

		for(i = 0; i < N; i++) {
			int pos = finishOrder[i] - 'A';
			if(cnt[pos] + 1 <= 5) {
				cnt[pos] += 1;
				sum[pos] += i;
			}
			mem[pos].push_back(i);
		}

		int pivot = 0;
		pair<int, int> vp[MAXN];

		for(i = 0; i < N; i++) if(cnt[i] >= 5) {
			vp[pivot++] = make_pair(sum[i], i);
		}

		sort(vp, vp + pivot, compare);

		for(i = 0; i < pivot; i++) ans += (char) vp[i].second + 'A';

		return ans;
	}
};
<%:testing-code%>
// Powered by FileEdit