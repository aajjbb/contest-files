// 2013-03-02T04:42:15+01:00
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

struct Quipu {
	int readKnots(string knots) {
		string to = "";

		for(int i = 0; i < knots.size(); i++) {
			int j = i + 1;
			while(j < knots.size() && knots[j] == knots[i]) {
				j += 1;
			}
			if(knots[i] == 'X') {
				to += (j - i) + '0';
			} else {
				if(j - i > 1) for(int k = i; k < j - 1; k++) to += '0';
			}
			i = j - 1;
		}
		int ans = 0;

		istringstream ss(to); ss >> ans;

		return ans;
	}
};


// Powered by FileEdit