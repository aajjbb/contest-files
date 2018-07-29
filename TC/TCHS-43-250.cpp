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

class TransformArray {
public:
	int doTransform(vector <int>);
};

int TransformArray::doTransform(vector <int> elements) {
	deque<int> q(elements.begin(), elements.end());

	int i, j, T, N = q.size();

	for (T = 0; ; T++) {
		if (q.size() < 2) return T;

		int id_a = -1, id_b = -1, diff = INT_MAX, sum = INT_MAX;

		N = q.size();

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) if (i != j) {
				int cur = abs(q[i] - q[j]);

				if (cur < diff || (cur == diff && q[i] + q[j] < sum)) {
					diff = cur;
					sum = q[i] + q[j];
					id_a = i, id_b = j;
				}
			}
		}

		q[id_a] -= 1;
		q[id_b] -= 1;

		sort (q.begin(), q.end());

		while (!q.empty() && q[0] <= 0) {
			q.pop_front();
			N -= 1;
		}
	}
}

//Powered by [KawigiEdit] 2.0!
