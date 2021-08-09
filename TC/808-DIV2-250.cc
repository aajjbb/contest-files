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

class IOIGuaranteedPlace {
public:
	vector <int> solve(int, vector <int>, vector <int>);
};

vector <int> IOIGuaranteedPlace::solve(int N, vector <int> day1scores, vector <int> day2scores) {
	vector<int> ans(N);

	for (int i = 0; i < N; i++) {
		int better = 0;
		int score = day1scores[i] + day2scores[i];


		for (int j = 0; j < N; j++) {
			if (i == j) continue;

			if (day1scores[j] + 300 > score) {
				better += 1;
			}
		}

		ans[i] = 1 + better;
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
