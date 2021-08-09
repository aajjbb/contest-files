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

using namespace std;

class SimilarDNA {
public:
	string areSimilar(string, string);
};

const int INF = 10101001;

int dp[60][60];

int func(int a, int b, const string& A, const string& B) {
	if (a >= A.size() || b >= B.size()) {
		return max(A.size() - a, B.size() - b);
	} else {
		int& ans = dp[a][b];

		if (ans == -1) {
			ans = INF;

			if (A[a] == B[b]) {
				ans = min(ans, func(a + 1, b + 1, A, B));
			} else {
				ans = min(ans, 1 + func(a, b + 1, A, B));
				ans = min(ans, 1 + func(a + 1, b, A, B));
				ans = min(ans, 1 + func(a + 1, b + 1, A, B));
			}
		}

		return ans;
	}
}

string SimilarDNA::areSimilar(string A, string B) {
	memset(dp, -1, sizeof(dp));

	int ans = func(0, 0, A, B);

	if (ans <= 2) {
		return "similar";
	} else {
		return "distinct";
	}
}

//Powered by [KawigiEdit] 2.0!
