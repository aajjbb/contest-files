// 09-12-2012 14:16:14+01:00	Submit	aajjbb	500	307.37
#line 61 "RogersPhenomenon.cpp"
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

struct RogersPhenomenon {
	int countTriggers(vector <int> set1, vector <int> set2) {
		int i;
		vector<int> ans;
		REP(i, set1.size()) {
			if(ok(set1, set2, set1[i])) ans.push_back(set1[i]);
		}
		REP(i, set2.size()) {
			if(ok(set2, set1, set2[i])) ans.push_back(set2[i]);
		}
		return (int) ans.size();
	}
	double mean(vector<int>& v) {
		int i;
		double sum = 0.0;
		REP(i, v.size()) sum += (double) v[i];
		return (double) sum / (double) v.size();
	}
	bool ok(vector<int> set1, vector<int> set2, int now) {
		double means1 = mean(set1);
		double means2 = mean(set2);
		set2.push_back(now);
		set1.erase(find(set1.begin(), set1.end(), now));
		double means1_new = mean(set1);
		double means2_new = mean(set2);
		return means1 < means1_new && means2 < means2_new;
	}
};


// Powered by FileEdit