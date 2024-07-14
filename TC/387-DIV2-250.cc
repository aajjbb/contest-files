// 10-14-2012 20:27:04	Submit	aajjbb	250	243.75
#line 67 "GuessingNextElement.cpp"
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

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;
struct GuessingNextElement {
	int guess(vector <int> A) {
		int i;
		set<int> ari, geo;
		REP(i, A.size()) if(i > 0) {
			ari.insert(A[i] - A[i - 1]);
			geo.insert(A[i] / A[i - 1]);
		}
		if(ari.size() == 1) {
			return A[A.size()-1] + (*ari.begin());
		} else {
			return A[A.size()-1] * (*geo.begin());
		}
	}
};

<%:testing-code%>
// Powered by FileEdit