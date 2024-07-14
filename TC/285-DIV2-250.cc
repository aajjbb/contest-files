// 09-18-2012 12:23:18+01:00	Submit	aajjbb	250	223.08
#line 48 "BasketsWithApples.cpp"
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

struct BasketsWithApples {
	int removeExcess(vector <int> apples) {
		int i, j, ans = 0;
		REP(i, apples.size()) {
			int outcome = 0;
			REP(j, apples.size()) {
				if(apples[j] >= apples[i]) outcome += apples[i];
			}
			ans = max(ans, outcome);
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit