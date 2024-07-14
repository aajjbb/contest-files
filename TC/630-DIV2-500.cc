// Submitted - 2014:08:22 05:10:23
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
#include <climits>
#include <ctime>

using namespace std;

class Egalitarianism3Easy {
public:
	int maxCities(int, vector <int>, vector <int>, vector <int>);
};

const int MAXN = 13;

int dst[MAXN][MAXN];

int Egalitarianism3Easy::maxCities(int n, vector <int> a, vector <int> b, vector <int> len) {
	for (int i = 0; i < n - 1; i++) {
		a[i] -= 1;
		b[i] -= 1;

		fill(dst[i], dst[i] + MAXN, INT_MAX / 3);
	}
	fill(dst[n-1], dst[n-1] + MAXN, INT_MAX / 3);

	for (int i = 0; i < n - 1; i++) {
		dst[a[i]][b[i]] = dst[b[i]][a[i]] = len[i];
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dst[i][j] = min(dst[i][j], dst[i][k] + dst[k][j]);
			}
		}
	}

	int ans = 1;

	for (int k = 0; k < (1 << n); k++) {
		if (__builtin_popcount(k) > ans) {
			set<int> curr;
			for (int i = 0; i < n; i++) {
				if (k & (1 << i)) {
					for (int j = 0; j < n; j++) {
						if (i != j && (k & (1 << j))) {
							curr.insert(dst[i][j]);
						}
					}
				}
			}
			if (curr.size() == 1) {
				ans = __builtin_popcount(k);
			}
		}
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!