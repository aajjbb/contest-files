// Submitted 2023-08-28 16:38:35

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

using namespace std;


class EllysNumberGuessing {
public:
	int getNumber(vector <int> guesses, vector <int> answers) {
		const int n = guesses.size();
		const int MAX_N = 1000000000;

		map<long long, int> cnt;
		int count_n = 0;
		long long poss_n = -1;

		for (int i = 0; i < n; i++) {
			long long pa = guesses[i] + answers[i];
			long long pb = guesses[i] - answers[i];

			if (pa >= 1 && pa <= MAX_N) {
				cnt[pa] += 1;
			}
			if (pb >= 1 && pb <= MAX_N) {
				cnt[pb] += 1;
			}
		}

		for (auto const& [key, value]: cnt) {
			if (value == n) {
				count_n += 1;
				poss_n = key;
			}
		}

		if (count_n == 1) {
			return poss_n;
		} else if (count_n == 2) {
			return -1;
		} else {
			return -2;
		}
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!