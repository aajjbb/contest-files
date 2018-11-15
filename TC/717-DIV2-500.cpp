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

class LexmaxReplace {
public:
	string get(string s, string t) {
		sort(t.rbegin(), t.rend());

		int t_pos = 0;

		for (int i = 0; i < s.size(); i++) {
			if (t_pos >= t.size()) break;

			if (s[i] < t[t_pos]) {
				s[i] = t[t_pos];
				t_pos++;
			}
		}

		return s;
	}
};

//Powered by KawigiEdit-pf 2.3.0!
