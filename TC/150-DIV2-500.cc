// 2013-02-26T16:19:06+01:00
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

int digit_sum(int x, int base) {
	int ans = 0;

	while(x > 0) {
		ans += (x % base);
		x /= base;
	}

	return ans;
}

bool func(int number, int base) {
	for(int i = 0; i < base * base * base; i += number) {
		if(digit_sum(i, base) % number != 0) return false;
	}
	return true;
}

struct InterestingDigits {
	vector <int> digits(int base) {
		vector<int> ans;

		for(int i = 2; i < base; i++) {
			if(func(i, base)) ans.push_back(i);
		}

		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit