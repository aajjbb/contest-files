// 04-14-2013 05:34:23+01:00	Submit	aajjbb	250	241.21
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

set<int> already;

int func(vector<int> candidates, int h) {
	int i, N = candidates.size(), close = INT_MAX, index = -1;
	for (i = 0; i < N; i++) if(!already.count(i)) {
		if(abs(candidates[i] - h) < close) {
			close = abs(candidates[i] - h);
			index = i;
		}
	}
	already.insert(index);
	return candidates[index];
}

struct SkipRope {
	vector <int> partners(vector <int> candidates, int height) {
		vector<int> ans(2);

		ans[0] = func(candidates, height);
		ans[1] = func(candidates, height);

		if(ans[0] > ans[1]) swap(ans[0], ans[1]);

		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit