// 2013-03-02T04:12:27+01:00
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

map<char, char> sub;

void build(void) {
	sub[' '] = ' ';
	sub['0'] = '5'; sub['5'] = '0';
	sub['1'] = '6';	sub['6'] = '1';
	sub['2'] = '7';	sub['7'] = '2';
	sub['3'] = '8';	sub['8'] = '3';
	sub['4'] = '9';	sub['9'] = '4';

	for(char c = 'A'; c < 'N'; c++) sub[c] = (c - 'A') + 'N';
	for(char c = 'a'; c < 'n'; c++) sub[c] = (c - 'a') + 'n';

	for(char c = 'N'; c <= 'Z'; c++) sub[c] = 'A' + (c - 'N');
	for(char c = 'n'; c <= 'z'; c++) sub[c] = 'a' + (c - 'n');
}

struct SuperRot {
	string decoder(string message) {
		build();

		for(int i = 0; i < message.size(); i++) message[i] = sub[message[i]];

		return message;
	}
};


// Powered by FileEdit