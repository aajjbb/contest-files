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

class ClientsList {
public:
	vector <string> dataCleanup(vector <string>);
};

bool compare(pair<string, string> a, pair<string, string> b) {
	a.first[0] = tolower(a.first[0]);
	b.first[0] = tolower(b.first[0]);

	a.second[0] = tolower(a.second[0]);
	b.second[0] = tolower(b.second[0]);

	if (a.second == b.second) {
		return a.first < b.first;
	} else {
		return a.second < b.second;
	}
}

vector <string> ClientsList::dataCleanup(vector <string> names) {
	int i;
	int N = (int) names.size();

	vector<pair<string, string> > vs;
	vector<string> ans;

	for (i = 0; i < N; i++) {
		string A, B;

		int pos = names[i].find(',');

		if (pos != string::npos) {
			B = names[i].substr(0, pos);
			A = names[i].substr(pos + 2, (int) names[i].size() - pos + 2);
		} else {
			pos = names[i].find(" ");
			A = names[i].substr(0, pos);
			B = names[i].substr(pos + 1, (int) names[i].size() - pos + 1);
		}

		vs.push_back(make_pair(A, B));
	}

	sort(vs.begin(), vs.end(), compare);

	for (i = 0; i < N; i++) ans.push_back(vs[i].first + " " + vs[i].second);

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!