// 2013-03-08T05:57:52+01:00
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

int ans = 0, numLength, allowed;
vector<string> forbidden;

void func(int id, string now) {
	if(id == numLength) {
		int tmp = 0;
		for(int i = 0; i < forbidden.size(); i++) {
			int p = now.find(forbidden[i]);
			while(p != string::npos) {
				p = now.find(forbidden[i], p + 1);
				tmp += 1;
			}
		}
		if(tmp < allowed) ans += 1;
		return;
	}
	func(id + 1, now + "c");
	func(id + 1, now + "d");
}

struct TennisRallies {
	int howMany(int _numLength, vector <string> _forbidden, int _allowed) {
		numLength = _numLength;
		forbidden = _forbidden;
		allowed = _allowed;

		func(0, "");

		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit