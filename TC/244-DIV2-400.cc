// 10-18-2012 18:36:22+01:00	Submit	aajjbb	400	384.32
#line 54 "PhonePad.cpp"
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

char numpad[4][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}, {'*','0','#'}};

int dist(char start, char end) {
	int i, j, k, l;
	REP(i, 4) REP(j, 3) REP(k, 4) REP(l, 3) {
		if(numpad[i][j] == start && numpad[k][l] == end) {
			return abs(i-k) + abs(j-l);
		}
	}
	return INT_MAX;
}

struct PhonePad {
	int fingerMovement(string phoneNumber) {
		int i, ans = 0, last = '5';

		REP(i, phoneNumber.size()) {
			ans += dist(last, phoneNumber[i]);
			last = phoneNumber[i];
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit