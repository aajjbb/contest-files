// 11-16-2012 01:16:25+01:00	Submit	aajjbb	250	219.96
#line 52 "ReversingBrackets.cpp"
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

struct  ReversingBrackets {
	string removeBrackets(string s) {
		REP(i, s.size()) if(s[i] == '[') {
			FOR(j, i + 1, s.size()) if(s[j] == ']') {
				string tmp = s.substr(i + 1, j - i - 1);
				reverse(tmp.begin(), tmp.end());
				s = s.substr(0, i) + tmp + s.substr(j + 1, s.size() - j + (j == s.size() - 1 ? -1 : 0));
			}
		}
		return s;
	}
};

<%:testing-code%>
// Powered by FileEdit