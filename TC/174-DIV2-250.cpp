// 10-14-2012 01:03:25+01:00	Submit	aajjbb	250	247.51
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
struct CrossWord {
	int countWords(vector <string> board, int size) {
		int i, j, k, len, ans = 0;

		REP(i, board.size()) {
			REP(j, board[0].size()) {
				if(board[i][j] == '.') {
					k = j, len = 0;
					while(k < board[i].size() && board[i][k] == '.') {
						k += 1; len += 1;
					}
					if(len == size) ans += 1;
					j = k;
				}
			}
		}
		return ans;
	}
};


// Powered by FileEdit
