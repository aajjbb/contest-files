// 09-06-2012 23:47:53+01:00	Submit	aajjbb	500	445.76
/*
 aajjbb
*/
#line 70 "DigitsSum.cpp"
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

struct DigitsSum {
 	int lastDigit(int n) {
		return rec(n);
	}
	int rec(int n) {
		if(n == 0) return 0;
		int len = 0, sum = 0;
		while(n > 0) {
			sum += n % 10; len += 1; n /= 10;
		}
		if(len == 1) return sum;
		return rec(sum);
	}
};

<%:testing-code%>
// Powered by FileEdit