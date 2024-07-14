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


class EqualizeBags {
public:
	string check(int N, vector <int> bags, int E) {
		int all_candy = accumulate(bags.begin(), bags.end(), 0);
		int exceeded = all_candy - N * *min_element(bags.begin(), bags.end());

		if (E < exceeded || E > all_candy) {
			return "impossible";
		} else {
			int remain = E - exceeded;

			if (remain % N == 0) {
				return "possible";
			} else {
				return "impossible";
			}
		}
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!