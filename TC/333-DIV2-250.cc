// 10-01-2012 03:09:59+01:00	Submit	aajjbb	250	226.37
#line 70 "ChessboardPattern.cpp"
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
struct ChessboardPattern {
	vector <string> makeChessboard(int rows, int columns) {
		vector<string> ans(rows, string(columns, '.'));
		int i, j, ok = 1;
		for(j = 1; j < columns; j++) {
			if(ok) {
				ans[rows-1][j] = 'X';
				ok = 0;
			} else {
				ok = 1;
			}
		}
		for(i = rows - 2; i >= 0; i--) {
			for(j = 0; j < columns; j++) {
				if(ans[i+1][j] == 'X') {
					ans[i][j] = '.';
				} else {
					ans[i][j] = 'X';
				}
			}
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit