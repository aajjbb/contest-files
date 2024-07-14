// 07-09-2014 04:28:18+01:00	Submit	aajjbb	1000	498.04
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
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

class ProbabilityTree {
public:
	vector <int> getOdds(vector <string>, int, int);
};

const int MAXN = 60;

double P[MAXN], NP[MAXN];
vector<int> tree_rep[MAXN];

vector <int> ProbabilityTree::getOdds(vector <string> tree, int lowerBound, int upperBound) {
	int N = tree.size();
	int parent;

	sscanf(tree[0].c_str(), "%lf", &P[0]);
	NP[0] = 100 - P[0];

    for (int i = 0; i < N; i++) tree_rep[i].clear();

	for (int i = 1; i < N; i++) {
		sscanf(tree[i].c_str(), "%d %lf %lf", &parent, &P[i], &NP[i]);
		tree_rep[parent].push_back(i);
	}

	vector<int> ans;

	queue<pair<int, int> > q;
	q.push(make_pair(0, -1));

	for ( ; !q.empty(); ) {
		int p = q.front().first;
		int parent = q.front().second;
		printf("%d\n", p);
		q.pop();

		if (parent != -1) {
			double PA = (P[p] * P[parent] + NP[p] * NP[parent]) / 100.0;
			double PB = 100.0 - PA;

			if (PA > lowerBound && PA < upperBound) {
				ans.push_back(p);
			}
			P[p] = PA;
			NP[p] = PB;
		} else {
			if (P[p] > lowerBound && P[p] < upperBound) {
				ans.push_back(p);
			}
		}
		for (int i = 0; i < (int) tree_rep[p].size(); i++) {
			q.push(make_pair(tree_rep[p][i], p));
		}
	}

	sort(ans.begin(), ans.end());

	return ans;
}

//Powered by [KawigiEdit] 2.0!
