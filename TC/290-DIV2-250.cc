// 11-03-2012 15:17:26+01:00	Submit	aajjbb	250	238.00
/*
aajjbb
*/
#line 70 "SpeedTyper.cpp"
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

struct SpeedTyper {
	string lettersToPractice(string letters, vector <int> times) {
		int N = times.size(), all = 0;
		vector<int> diff(N, 0);
		diff[0] = all = times[0];

		FOR(i, 1, N) {
			diff[i] = times[i] - times[i-1];
			all += diff[i];
		}
		int mean = (int) all / N;

		string ans = "";

		REP(i, N) if(diff[i] > mean) ans += letters[i];

		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit