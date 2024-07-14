// Submitted - 2014-05-11 03:52:57
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

class CandidatesSelectionEasy {
public:
	vector <int> sort(vector <string>, int);
};

vector<string> score;
int x;

bool cmp(int a, int b) {
	return score[a][x] == score[b][x] ? a < b : score[a][x] < score[b][x];
}

vector <int> CandidatesSelectionEasy::sort(vector<string> _score, int _x) {
	score = _score;
	x = _x;

	int N = (int) score.size();
	vector<int> vs(N, 0);

	for (int i = 0; i < N; i++) vs[i] = i;

	::sort(vs.begin(), vs.end(), cmp);

	return vs;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!