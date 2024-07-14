// 10-15-2012 03:12:05+01:00	Submit	aajjbb	250	226.65
#line 81 "Segments.cpp"
/* aajjbb */
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;
struct Segments {
	string intersection(vector <int> s1, vector <int> s2) {
		int x, y, match = 0;

		if(s1[0] > s1[2]) swap(s1[0], s1[2]);
		if(s1[1] > s1[3]) swap(s1[1], s1[3]);
		if(s2[0] > s2[2]) swap(s2[0], s2[2]);
		if(s2[1] > s2[3]) swap(s2[1], s2[3]);

		for(x = -1000; x <= 1000; x++) {
			for(y = -1000; y <= 1000; y++) {
				if(x >= s1[0] && x >= s2[0] && x <= s1[2] && x <= s2[2] && y >= s1[1] && y >= s2[1] && y <= s1[3] && y <= s2[3]) {
					match += 1;
				}
			}
		}
		if(match == 0) {
			return "NO";
		} else if(match == 1) {
			return "POINT";
		} else {
			return "SEGMENT";
		}
	}
};


// Powered by FileEdit
