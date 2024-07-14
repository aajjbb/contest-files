// 06-17-2013 05:43:17+01:00	Submit	aajjbb	450	420.27
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

class Arrows {
public:
	int longestArrow(string);
};

int Arrows::longestArrow(string s) {
	int i, j, ans = INT_MIN;

	int N = s.size();

	if (s.find(">") != string::npos || s.find("<") != string::npos) ans = 1;

	for (i = 0; i < N; i++) {
		if (s[i] == '<' && i + 1 < N && (s[i+1] == '-' || s[i+1] == '=')) {
			char next = s[i+1];
			for (j = i + 1 ; j < N && s[j] == next; j++) { }
			ans = max(ans, j - i);
		}
		if (s[i] == '>' && i - 1 > -1 && (s[i-1] == '-' || s[i-1] == '=')) {
			char next = s[i-1];
			for (j = i - 1 ; j > -1 && s[j] == next; j--) { }
			ans = max(ans, i - j);
		}
	}

	return ans == INT_MIN ? -1 : ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!