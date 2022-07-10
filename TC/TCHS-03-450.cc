// Submitted 19-11-2018 17:01

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


class KidsWordGame {
public:
	int getCheater(vector <string> first, vector <string> second, vector <string> third) {
		int N = first.size();

		for (int i = 0; i < N; i++) {
			if (second.size() > i) {
				if (second[i].empty()) {
					return 1;
				}
				string f_be = second[i].substr(1, second[i].size() - 1);
				string f_ed = second[i].substr(0, second[i].size() - 1);

				if (!(f_be == first[i] || f_ed == first[i])) {
					return 1;
				}
			}

			if (third.size() > i) {
				if (third[i].empty()) {
					return 2;
				}
				string s_be = third[i].substr(1, third[i].size() - 1);
				string s_ed = third[i].substr(0, third[i].size() - 1);

				if (!(s_be == second[i] || s_ed == second[i])) {
					return 2;
				}
			}

			if (i + 1 < N) {
				if (first[i + 1].empty()) {
					return 3;
				}
				string t_be = first[i+1].substr(1, first[i+1].size() - 1);
				string t_ed = first[i+1].substr(0, first[i+1].size() - 1);

				if (third.size() > i) {
					if (!(t_be == third[i] || t_ed == third[i])) {
						return 3;
					}
				}
			}
		}

		return -1;
	}
};

//Powered by KawigiEdit-pf 2.3.0!
