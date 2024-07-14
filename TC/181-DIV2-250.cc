// 10-02-2012 14:19:45+01:00	Submit	aajjbb	250	246.52
#line 61 "KiloMan.cpp"
/*
 aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct KiloMan {
	int hitsTaken(vector <int> pattern, string jumps) {
		int i, hits = 0;
		REP(i, pattern.size()) {
			if((pattern[i] >= 3 && jumps[i] == 'J') || (pattern[i] <= 2 && jumps[i] == 'S')) {
				hits++;
			}
		}
		return hits;
	}
};

<%:testing-code%>
// Powered by FileEdit