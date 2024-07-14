// 2013-03-08T05:42:55+01:00
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

int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool leap(int num) {
	return ((num % 4 == 0 && num % 100 != 0) || (num % 4 == 0 && num % 400 == 0));
}

struct CalendarRecycle {
	int useAgain(int year) {
		bool isLeap = leap(year);
		int w = 0, current = 0;

		while(true) {
			year += 1;
			current += 1; current %= 7;
			bool now = leap(year);

			if(now) {
				current += 1; current %= 7;
			}

			if(now == isLeap && current == w) break;
		}

		return year;
	}
};
<%:testing-code%>
// Powered by FileEdit