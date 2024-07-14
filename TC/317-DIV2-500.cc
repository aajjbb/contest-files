// 02-26-2013 02:22:45+01:00	Submit	aajjbb	500	150.00
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

ll strtoint(string s) {
	ll ans = 0;

	for(int i = s.size() - 1, j = 0; i >= 0; i--, j++) {
		ans += ((int) pow(10., j)) * s[i] - '0';
	}

	return ans;
}

string inttostr(ll s) {
	string ans = "";
	while(s > 0) {
		ans += s%10 + '0';
		s /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

set<ll> pal;
set<ll>::iterator it;

void rec(string base) {
	if(!base.empty() && base[0] != '0') {
		pal.insert((ll)atoi(base.c_str()));
	}

	if(base.size() >= 8) return;

	for(char c = '0'; c <= '9'; c++) {
		rec(string(c + base + c));
	}
}

struct PalindromicNumbers {
	int countPalNums(int lower, int upper) {
		rec("");
		for(char c = '0'; c <= '9'; c++) rec(string(1, c));

		int ans = 0;

		for_each(it, pal) {
			if(*it >= lower && *it <= upper) {
				ans += 1;
			}
		}
		return ans;
	}
};