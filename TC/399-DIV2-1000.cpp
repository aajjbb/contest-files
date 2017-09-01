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

struct AvoidingProduct {
	vector <int> getTriple(vector <int> a, int n) {
		bool used[1024];
		memset(used, 0, sizeof(used));

		for(int i = 0; i < a.size(); i++) used[a[i]] = true;

		vector<int> list;

		for(int i = 1; i <= 1010; i++) {
			if(!used[i]) {
				list.push_back(i);
			}
		}
		int aa = 0, b = 0, c = 0;
		int ans = 1 << 30;

		for(int i = 0; i < (int) list.size(); i++) {
			for(int j = i; j < (int) list.size(); j++) {
				for(int k = j; k < (int) list.size(); k++) {
					int mx = abs(list[i] * list[j] * list[k] - n);
					if(mx < ans) {
						ans = mx;
						aa = list[i];
						b = list[j];
						c = list[k];
					}
				}
			}
		}
		vector<int> as;
		as.push_back(aa);
		as.push_back(b);
		as.push_back(c);
		return as;
	}
};

// Powered by FileEdit
