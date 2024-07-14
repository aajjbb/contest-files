// 09-13-2012 15:06:30+01:00	Submit	aajjbb	250	227.02
#line 50 "CssPropertyConverter.cpp"
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

struct CssPropertyConverter {
	string getCamelized(string str) {
		int i;
		REP(i, str.size()) {
			if(str[i] == '-' && i + 1 < str.size()) {
				str[i+1] = toupper((char)str[i+1]);
				str = str.substr(0, i) + str.substr(i+1, str.size()-i+1);
			}
		}
		return str;
	}
};

<%:testing-code%>
// Powered by FileEdit