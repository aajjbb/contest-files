// Submitted - 2014:08:03 21:48:44
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

class IncrementingSequence {
public:
	string canItBeDone(int, vector <int>);
};

string IncrementingSequence::canItBeDone(int k, vector <int> A) {
	int N = (int) A.size();
	vector<bool> used(N + 1, false), filled(N + 1, false);

	sort(A.begin(), A.end());

	for (int i = 0; i < N; i++) {
		if (A[i] > N) return "IMPOSSIBLE";
		if (!used[A[i]]) {
			used[A[i]] = true;
			filled[i] = true;
		}
	}

	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			for (int j = 0; j < N; j++) {
				if (!filled[j] && i >= A[j]) {
					if ((i - A[j]) % k == 0) {
						used[i] = true;
						filled[j] = true;
						break;
					}
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		if (!used[i]) {
			return "IMPOSSIBLE";
		}
	}
	return "POSSIBLE";

}

//Powered by [KawigiEdit] 2.0!
