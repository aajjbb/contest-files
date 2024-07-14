// Submitted - 2014-09-26 03:51:25
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
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;

class ShoppingSurveyDiv2 {
public:
	int minValue(int, vector <int>);
};

bool cmp(set<int> a, set<int> b) {
	return a.size() < b.size();
}

int ShoppingSurveyDiv2::minValue(int N, vector <int> s) {
	int P[N];

	memset(P, 0, sizeof(P));

	int id = 0;
	int M = (int) s.size();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < s[i]; j++) {
			P[id] += 1;
			id = (id + 1) % N;
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		if (P[i] == M) {
			ans += 1;
		}
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!