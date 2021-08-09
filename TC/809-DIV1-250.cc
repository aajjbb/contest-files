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

class LunchLine {
public:
	long long simulate(int, int, int, int, int, int, int);
};

long long LunchLine::simulate(int N, int M, int A, int B, int C, int D, int E) {
	vector<pair<long long, int> > VP(N);
	vector<long long> K(max(2, M));

	K[0] = A;
	K[1] = B;

	for (int i = 2; i < M; i++) {
		K[i] = ((C * K[i - 1]) % N + (D * K[i - 2]) % N + E) % N;
		K[i] += N;
		K[i] %= N;
	}

	for (int i = 0; i < N; i++) {
		VP[i].first = i;
		VP[i].second = i;
	}

	for (int i = 0; i < M; i++) {
		VP[K[i]].first = N + i;
	}

	sort(VP.begin(), VP.end());

	long long ans = 0;

	for (int i = 0; i < N; i++) {
		ans += (i * (long long) VP[i].second);
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
