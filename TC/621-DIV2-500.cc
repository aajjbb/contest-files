// Submitted - 2014-05-21 17:58:56
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumbersChallenge {
public:
	int MinNumber(vector <int>);
};

const int MAXN = 20000005;
int can[MAXN][2];

int NumbersChallenge::MinNumber(vector <int> S) {
	int N = (int) S.size();
	for (int i = 0; i < N; i++) {
		can[S[i]][1] = true;
		can[S[i]][0] = (1 << i);

	}
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j < N; j++) {
			if (i - S[j] >= 0) {
				if (!(can[i - S[j]][0] & (1 << j))) {
					can[i][1] = true;
					can[i][0] = can[i - S[j]][0] | (1 << j);
				}
			}
		}
		if (!can[i][1]) {
			return i;
		}
	}
	return -1;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!