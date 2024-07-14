// Submitted - 2018-02-12 14:56:44
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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
#include <climits>

using namespace std;


class MoveStonesEasy {
public:
	int get(vector <int> a, vector <int> b) {
		if (accumulate(a.begin(), a.end(), 0) != accumulate(b.begin(), b.end(), 0)) {
			return -1;
		}

		int N = a.size();
		int answer = 0;

		while (1) {
			int best_diff = INT_MAX;
			int bi = -1;
			int bj = -1;

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (a[i] > b[i] && b[j] > a[j]) {
						if (abs(i - j) < best_diff) {
							best_diff = abs(i - j);
							bi = i;
							bj = j;
						}
					}
				}
			}

			if (best_diff == INT_MAX) break;

			int amount = min(a[bi] - b[bi], b[bj] - a[bj]);

			a[bi] -= amount;
			a[bj] += amount;

			answer += amount * abs(bi - bj);
		}

		return answer;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!