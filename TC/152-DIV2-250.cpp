// 2013-03-01T19:40:30+00:01 Submit aajjbb 250 237.34
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

double X = 0.25, R;

void normalize(void) {
	for(int i = 1; i <= 200000; i++) {
		X = (double) R * X * (1-X);
	}
}

double interval(void) {
	double l = numeric_limits<double>::max();
	double r = numeric_limits<double>::min();

	for(int i = 1; i <= 1000; i++) {
		X = (double) R * X * (1-X);
		l = min(l, X);
		r = max(r, X);
	}

	return r - l;
}


struct FixedPointTheorem {
	double cycleRange(double _R) {
		R = _R;
		normalize();
		return interval();
	}
};

<%:testing-code%>
// Powered by FileEdit