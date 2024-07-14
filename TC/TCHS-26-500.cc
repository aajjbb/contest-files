// 2013-06-09T05:33:08+01:00
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

int rec(string s) {
	if (s.size() < 3) return s.size();

	if (s.size() >= 3 && s[1] == '(') {
		int i, mult = s[0] - '0', buff = 1;

		for (i = 2; i < s.size() && buff != 0; i++) {
			if (s[i] == '(') buff++;
			else if (s[i] == ')') buff--;
		}

		return mult * rec(s.substr(2, i - 3)) + rec(s.substr(i));

	} else {
		return 1 + rec(s.substr(1, s.size() - 1));
	}
}

struct CompressedString {
	int getLength(string s) {
		return rec(s);
	}
};

// Powered by FileEdit
