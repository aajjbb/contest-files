// 09-20-2012 21:14:33+01:00	Submit	aajjbb	250	242.43
#line 52 "Chivalry.cpp"
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

struct Chivalry {
	string getOrder(string first, string second) {
		string ans = "";

		while(!first.empty() && !second.empty()) {
			char f = *first.begin();
			char s = *second.begin();

			if(f == s) {
				ans += f;
				first.erase(first.begin());
			} else {
				ans += 'W';
				if(f == 'W') {
					first.erase(first.begin());
				} else {
					second.erase(second.begin());
				}
			}
		}
		if(!first.empty()) ans += first;
		if(!second.empty()) ans += second;
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit