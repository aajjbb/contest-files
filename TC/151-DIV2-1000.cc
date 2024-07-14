// 2011-11-17T01:08:10+01:00
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
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long int64;

int tot = 0;

vector<int> merge(vector<int>& b, vector<int>& c) {
	vector<int> a;

	while(!b.empty() && !c.empty()) {
		tot++;
		if(*b.begin() < *c.begin()) {
			a.push_back(*b.begin());
			b.erase(b.begin());
		} else if(*b.begin() > *c.begin()) {
			a.push_back(*c.begin());
			c.erase(c.begin());
		} else {
			a.pb(*b.begin());
			a.pb(*c.begin());
			b.erase(b.begin());
			c.erase(c.begin());
		}
	}
	while(!b.empty()) { a.pb(*b.begin()); b.erase(b.begin()); }
	while(!c.empty()) { a.pb(*c.begin()); c.erase(c.begin()); }
	return a;
}

vector<int> mergeSort(vector<int>& a) {
	if(sz(a) <= 1) {
		return a;
	}
	vector<int> b;
	vector<int> c;

	for(int i = 0; i < sz(a) / 2; i++) {
		b.pb(a[i]);
	}
	for(int i = sz(a) / 2; i < sz(a); i++) {
		c.pb(a[i]);
	}
	vector<int> sb = mergeSort(b);
	vector<int> sc = mergeSort(c);
	return merge(sb, sc);
}

struct MergeSort {
	int howManyComparisons(vector <int> numbers) {
		mergeSort(numbers);
		return tot;
	}
};

<%:testing-code%>
// Powered by FileEdit