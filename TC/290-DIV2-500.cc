// 11-03-2012 15:43:41+01:00	Submit	aajjbb	500	309.00
/*
aajjbb
*/
#line 68 "BrokenClock.cpp"
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

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct BrokenClock {
	int fewestClicks(string clockTime, string currentTime) {
		return ans(atoi(clockTime.substr(0, 2).c_str()), atoi(clockTime.substr(3, 5).c_str()), atoi(currentTime.substr(0, 2).c_str()), 		atoi(currentTime.substr(3, 5).c_str()));
	}

	int ans(int baseh, int basem, int goalh, int goalm) {
		int ans = 0;

		while(baseh < goalh && basem < goalm) {
			ans += 1;
			baseh += 1;
			basem += 1;
			if(baseh == 24) baseh = 0;
			if(basem == 60) basem = 0;
		}
		while(baseh > goalh && basem < goalm) {
			ans += 1;
			baseh += 1;
			basem += 1;
			if(baseh == 24) baseh = 0;
			if(basem == 60) basem = 0;
		}
		while(baseh > goalh && basem > goalm) {
			ans += 1;
			baseh += 1;
			basem += 1;
			if(baseh == 24) baseh = 0;
			if(basem == 60) basem = 0;
		}
		while(baseh > goalh) {
			baseh += 1; ans += 1;
			if(baseh == 24) baseh = 0;
		}
		while(basem > goalm) {
			basem += 1; ans += 1;
			if(basem == 60) basem = 0;
		}
		while(baseh < goalh) {
			baseh += 1; ans += 1;
			if(baseh == 24) baseh = 0;
		}
		while(basem < goalm) {
			basem += 1; ans += 1;
			if(basem == 60) basem = 0;
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit