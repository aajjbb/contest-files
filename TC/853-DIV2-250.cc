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


class SkyscraperElevator {
public:
	int simulate(int N, vector <int> people) {
		int total_time = 0;
		int curr_floor = 0;

		for (int i = 0; i < (int) people.size(); i++) {
			int lift_time = curr_floor + people[i];
			int stair_time = 20 * people[i];

			if (lift_time <= stair_time) {
				total_time += lift_time;
				curr_floor = people[i];
			} else {
				total_time += stair_time;
			}
		}

		return total_time;
	}
};


<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!