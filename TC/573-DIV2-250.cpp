/*aajjbb*/
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

struct SkiResortsEasy {
	int minCost(vector <int> altitude) {
		int ans = 0;
		
		for(int i = 1; i < altitude.size(); i++) {
			if(altitude[i] > altitude[i - 1]) {
				ans += altitude[i] - altitude[i - 1];
				altitude[i] = altitude[i - 1];
			}
		}		
		
		return ans;
	}
};


// Powered by FileEdit
