// 2018-07-29T21:13:43+01:00
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


class WebBrowser {
public:
	vector <string> getSequence(vector <string> actions) {
		deque<string> back, forward;
		vector<string> loaded_pages;
		string current = "";

		for (string action: actions) {
			if (action == "BACK") {
				if (back.empty()) {
					continue;
				}
				if (current != "") {
					forward.push_front(current);
				}
				current = back.back();
				back.pop_back();

				loaded_pages.push_back(current);
			} else if (action == "FORWARD") {
				if (forward.empty()) {
					continue;
				}
				if (current != "") {
					back.push_back(current);
				}
				current = forward.front();
				forward.pop_front();

				loaded_pages.push_back(current);
			} else {
				if (action == current) {
					continue;
				}
				if (current != "") {
					back.push_back(current);
				}
				current = action;
				forward.clear();

				loaded_pages.push_back(current);
			}
		}

		return loaded_pages;
	}
};

//Powered by KawigiEdit-pf 2.3.0!
