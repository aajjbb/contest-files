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
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class CubeStackingGame {
public:
	int stk[10][4];

	int global_best = 1;

	int MaximumValue(int n, vector <int> c1, vector <int> c2, vector <int> c3, vector <int> c4) {
		rec(0, n, c1, c2, c3, c4);
		return global_best;
	}

	void rec(int pos, int n, vector<int> c1, vector<int> c2, vector<int> c3, vector<int> c4) {
		global_best = max(global_best, pos);

		if (pos == n) return;
		vector<int> colors = {c1[pos], c2[pos], c3[pos], c4[pos]};

		for (int r = 0; r < 8; r++) {
			set<int> sets[4];
			bool valid = true;

			for (int i = 0; i < 4; i++) {
				stk[pos][i] = colors[i]; //1 2 3 4 - 3 4 1 2

				for (int j = 0; j <= pos; j++) {
					sets[i].insert(stk[j][i]);
				}
				if (sets[i].size() != pos + 1) {
					valid = false;
				}
			}
			if (valid) {
				rec(pos + 1, n, c1, c2, c3, c4);
			}
			rotate(colors, r);
		}
	}

	void rotate(vector<int>& arg, int rotate) {
		const int n = arg.size();
		vector<int> other = arg;

		if (rotate % 3 == 0) {
			swap(arg[0], arg[2]);
		} else if (rotate % 3 == 1) {
			swap(arg[1], arg[3]);
		} else {
			for (int i = 0; i < n; i++) {
				arg[i] = other[(i + 1) % n];
			}
		}
	}
};

//Powered by KawigiEdit-pf 2.3.0!
