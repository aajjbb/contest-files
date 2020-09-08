// 2020-09-01 01:04 - 211.45
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
#include <ctime>

using namespace std;

class TapeMeasure {
public:
	vector <string> draw(int, int);
};

vector <string> TapeMeasure::draw(int leftMark, int rightMark) {
	const int MAX_TAPE = 20020;
	const char MARK = '#';

	vector<string> tape(5, string(MAX_TAPE, ' '));

	for (int i = 0; i < MAX_TAPE; i++) {
		tape[0][i] = MARK;

		if (i % 2 == 0) {
			tape[1][i] = MARK;
		}
		if (i % 10 == 0) {
			tape[2][i] = MARK;
		}
		if (i % 20 == 0) {
			tape[3][i] = MARK;

			string i_as_str = to_string(i / 2);

			for (int j = 0; i + j < MAX_TAPE && j < i_as_str.size(); j++) {
				tape[4][i + j] = i_as_str[j];
			}
		}
	}

	vector<string> ans(5);

	for (int i = 2 * leftMark; i <= 2 * rightMark; i++) {
		for (int j = 0; j < 5; j++) {
			ans[j] += tape[j][i];
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
