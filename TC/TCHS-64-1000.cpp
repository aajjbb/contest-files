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


class CommanderIdol {
public:
	const int INF = 1000100;

	int getMaxPopularity(vector <string> roads) {
		const int N = roads.size();

		vector<int> dist(N, INF);
		priority_queue<pair<int, int> > q;

		dist[0] = 0;
		q.push(make_pair(0, 0));

		while (!q.empty()) {
			int curr_dist = -q.top().first;
			int curr_pos = q.top().second;
			q.pop();

			if (dist[curr_pos] < curr_dist) {
				continue;
			}

			for (int i = 0; i < N; i++) {
				if (roads[curr_pos][i] == '-') {
					continue;
				}

				int potential_dist = curr_dist + (roads[curr_pos][i] - '0');

				if (dist[i] > potential_dist) {
					dist[i] = potential_dist;
					q.push(make_pair(-potential_dist, i));
				}
			}
		}

		int farthest = *max_element(dist.begin(), dist.end());

		if (farthest >= INF) {
			return -1;
		}

		int ans = 0;

		for (int i = 1; i < N; i++) {
			ans += farthest - dist[i];
		}

		return ans;
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
