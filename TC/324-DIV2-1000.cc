// 10-23-2012 16:52:49+01:00	Submit	aajjbb	1000	999.53
#line 56 "ProductBundling.cpp"
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

struct ProductBundling {
	int howManyBundles(vector <string> data) {
		int i, j;
		set<ll> s;

		REP(j, data[0].size()) {
			ll hash = 1;
			REP(i, data.size()) if(data[i][j] == '1') {
				hash += (ll) 1LL << i;
			}
			s.insert(hash);
		}
		return (int) s.size();
	}
};

<%:testing-code%>
// Powered by FileEdit