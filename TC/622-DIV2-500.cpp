// Submitted - 2014:06:02 17:49:14
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

class BoxesDiv2 {
public:
	int findSize(vector <int>);
};

int func(int x) {
	int i = 1;

	for ( ; ; ) {
		if (i >= x) {
			return i;
		}
		i = 2 * i;
	}
	return -1;
}

int BoxesDiv2::findSize(vector <int> candyCounts) {
	int N = (int) candyCounts.size();

	vector<int> vs(N);

	for (int i = 0; i < N; i++) {
		vs[i] = func(candyCounts[i]);
	}
	for ( ; vs.size() > 1; ) {
		sort(vs.begin(), vs.end());
		vs.push_back(func(vs[0] + vs[1]));
		vs.erase(vs.begin(), vs.begin() + 2);
	}
	return vs[0];
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!