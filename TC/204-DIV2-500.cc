// 10-05-2012 01:31:56+01:00	Submit	aajjbb	500	295.39
/*aajjbb*/
#line 50 "Aaagmnrs.cpp"
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

struct Aaagmnrs {
	vector <string> anagrams(vector <string> phrases) {
		int i, j, N = phrases.size();
		vector<string> ans;
		vector<bool> used(N, false);

		REP(i, N) if(!used[i]) {
			FOR(j, i + 1, N) if(!used[j]) {
				if(check(phrases[i], phrases[j])) {
					used[j] = true;
				}
			}
		}
		REP(i, N) if(!used[i]) ans.push_back(phrases[i]);

		return ans;
	}
	bool check(string a, string b) {
		int countA[26] = {0}, countB[26] = {0};

		for(int i = 0; i < a.size(); i++) if(a[i] != ' ') {
			countA[tolower(a[i])-'a'] += 1;
		}
		for(int i = 0; i < b.size(); i++) if(b[i] != ' ') {
			countB[tolower(b[i])-'a'] += 1;
		}

		for(int i = 0; i < 26; i++) {
			if(countA[i] != countB[i]) return false;
		}
		return true;
	}
};

<%:testing-code%>
// Powered by FileEdit