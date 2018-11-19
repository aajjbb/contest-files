// Submitted 19-11-2018

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


class CrazyCompetition {
public:
	const double INF = 100010100100.0;

	int getValue(char c) {
		if (c >= 'a' && c <= 'z') {
			return c - 'a' + 1;
		} else if (c >= 'A' && c <= 'Z') {
			return -(c - 'A') - 1;
		} else {
			return 0;
		}
	}

	double differenceTemperature(int daysSummer, int daysWinter, vector <string> temperature) {
		string whole_temp = "";

		for (string st : temperature) {
			whole_temp += st;
		}

		vector<double> average_summer(whole_temp.size(), 0);
		vector<double> average_winter(whole_temp.size(), 0);

		double ans = -INF;
		double curr_sum = 0.0;

		for (int i = 0; i < daysSummer - 1; i++) {
			curr_sum += getValue(whole_temp[i]);
		}

		for (int i = daysSummer - 1; i < whole_temp.size(); i++) {
			if (i - daysSummer >= 0) {
				curr_sum -= getValue(whole_temp[i - daysSummer]);
			}
			curr_sum += getValue(whole_temp[i]);

			average_summer[i] = curr_sum / (double) daysSummer;
		}

		curr_sum = 0;

		for (int i = 0; i < daysWinter - 1; i++) {
			curr_sum += getValue(whole_temp[i]);
		}

		for (int i = daysWinter - 1; i < whole_temp.size(); i++) {
			if (i - daysWinter >= 0) {
				curr_sum -= getValue(whole_temp[i - daysWinter]);
			}
			curr_sum += getValue(whole_temp[i]);

			average_winter[i] = curr_sum / (double) daysWinter;
		}
		// 1 3 abba
		for (int i = daysWinter - 1; i < whole_temp.size(); i++) {
			for (int j = i + daysSummer; j < whole_temp.size(); j++) {
				ans = max(ans, average_summer[j] - average_winter[i]);
			}
		}
		for (int i = daysSummer - 1; i < whole_temp.size(); i++) {
			for (int j = i + daysWinter; j < whole_temp.size(); j++) {
				ans = max(ans, average_summer[i] - average_winter[j]);
			}
		}

		return ans;
	}
};
<%:testing-code%>
//Powered by KawigiEdit-pf 2.3.0!
