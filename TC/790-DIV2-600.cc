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
#include <cstring>
#include <queue>

using namespace std;

class BobtheBuilder {
public:
	int minimumPrice(int, int, int);
};

const int INF = 10101001;
const int MAX_H = 50010;

int BobtheBuilder::minimumPrice(int B, int K, int H) {
	vector<int> dist(MAX_H, INF);
	dist[B] = 0;

	priority_queue<pair<int, int> > pq;
	pq.push({0, B});

	while (!pq.empty()) {
		int curr_dist = -pq.top().first;
		int curr_val = pq.top().second;
		pq.pop();

		if (curr_dist > dist[curr_val]) {
			continue;
		}

		if (curr_val + K < MAX_H && dist[curr_val + K] > curr_dist + 1) {
			dist[curr_val + K] = curr_dist + 1;
			pq.push({-(curr_dist + 1), curr_val + K});
		}

		int base = (int) sqrt(curr_val) + 1;
		//cout << curr_val << " " << base << endl;

		for (int i = 1; i <= base; i++) {
			if (curr_val % i != 0) {
				continue;
			}
			int comp = curr_val / i;

			if (dist[i] > curr_dist) {
				dist[i] = curr_dist;
				pq.push({-curr_dist, i});
			}
			if (dist[comp] > curr_dist) {
				dist[comp] = curr_dist;
				pq.push({-curr_dist, comp});
			}
		}
	}

	int ans = dist[H];

	if (ans >= INF) {
		ans = -1;
	}

	return ans;

}

//Powered by [KawigiEdit] 2.0!
