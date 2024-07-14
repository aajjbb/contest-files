// 2018-03-31T04:21:36+01:00
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


class DeckOfCards {
public:
	string IsValid(int n, vector <int> value, string suit) {
		set<pair<int, char> > st;

		for (int i = 0; i < n; i++) {
			st.insert(make_pair(value[i], suit[i]));
		}

		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				pair<int, char> pa = make_pair(value[i], suit[j]);
				pair<int, char> pb = make_pair(value[j], suit[i]);

				if (!(st.count(pa) && st.count(pb))) {
					return "Not perfect";
				}
			}
		}
		if (st.size() == n) {
			return "Perfect";
		} else {
			return "Not perfect";
		}
	}
};

//Powered by KawigiEdit-pf 2.3.0!
