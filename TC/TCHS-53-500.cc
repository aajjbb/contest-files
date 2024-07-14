// Incomplete Solution
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

int strToInt(string s) {
	int ans = 0, p = 0;

	for(int i = s.size() - 1; i >= 0; i--) {
		ans += (s[i] - '0') + p;
		p = (p == 0) ? 10 : p *= 10;
	}

	return ans;
}

string intToStr(int s) {
	string ans = "":

	while(s) {
		int curr = s % 10;
		ans = ans + char(curr + '0');
		s /= 10;
	}

	return ans;
}

int numerator, denominator;
double rate;
set<pair<int, int> > s;

void rec(string num, string denom) {
	int a = strToInt(num), b = strToInt(denom);

	double avg = (double) a / (double) b;

	if(avg == rate) {
		s.insert(make_pair(a, b));
		return;
	}
	for(int i = 0; i < num.size(); i++) {
		for(int j = 0; j < denom.size(); j++) if(num[i] == denom[j]) {
			string new_num = num[i].substr(0, i) + num[i].substr(i+1, num[i].size() - i + 1);
			string new_denom = denom[j].substr(0, j) + denom[j].substr(j+1, denom[j].size() - j + 1);

			rec(new_num, new_denom);
		}
	}
}

struct AnomalousCancellation {
	string reducedFraction(int _numerator, int _denominator) {
		numerator = _numerator;
		denominator = _denominator;

		rate = (double) numerator / (double) denominator;

		s.insert(make_pair(numerator, denominator));

		rec(numerator, denominator);

		return *s.begin();
	}
};
<%:testing-code%>
// Powered by FileEdit