// 2012-05-24T02:01:50+01:00

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
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <ctype.h>
#include <time.h>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;

struct FrequentPairs {
	int mostFrequent(vector <string> words) {
		int i, j;
		map<string, int> mp; mp.clear();

		REP(i, sz(words)) {
			for(j = 0; j < sz(words[i]) - 1; j++) {
				string tmp = "";
				tmp += words[i][j];
				tmp += words[i][j + 1];
				sort(tmp.begin(), tmp.end());
				mp[tmp] += 1;
			}
		}
		int mx = 0;
		for(map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
			if(it->second > mx) {
				mx = it->second;
			}
		}
		return mx;
	}
};

<%:testing-code%>
// Powered by FileEdit
