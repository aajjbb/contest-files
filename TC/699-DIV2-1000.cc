#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <climits>

using namespace std;

class FromToDivisibleDiv2 {
public:
	int shortest(int, int, int, vector <int>, vector <int>);
};

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

const int INF = INT_MAX / 4;

int FromToDivisibleDiv2::shortest(int N, int S, int T, vector <int> a, vector <int> b) {
	const int M = a.size();

	queue<int> q;
	vector<int> dist(M, 0);

	for (int i = 0; i < M; i++) {
		if (S % a[i] == 0) {
			dist[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		if (T % b[curr] == 0) {
			return dist[curr];
		}

		for (int i = 0; i < M; i++) {
			if (lcm((long long) b[curr], (long long) a[i]) <= N && dist[i] == 0) {
				dist[i] = dist[curr] + 1;
				q.push(i);
			}
		}
	}

	return -1;
}

//Powered by [KawigiEdit] 2.0!
