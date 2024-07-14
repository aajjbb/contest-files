// 01-13-2013 01:57:21+01:00	Submit	aajjbb	500	150.00
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

struct DollSets {
	int maximumQuantity(vector <int> doll, int K) {
		int i, j, N = doll.size(), ans = 0;

		sort(doll.begin(), doll.end());

		vector<bool> used(N, false);

		REP(i, N) FOR(j, i + 1, N) if(!used[i] && !used[j] && doll[i]*K == doll[j]) {
			used[i] = used[j] = true;
			ans += 1;
		}

		return ans;
	}
};


// Powered by FileEdit
