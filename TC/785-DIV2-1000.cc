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

class EllysNimDiv2 {
public:
	int getMin(vector <int>);
};

const int INF = 1000005;
const int MAX_ADD = 1024;

int dp[51][2100];

int func(int pos, int curr_xor, const vector<int>& A) {
	if (pos == A.size()) {
		return curr_xor == 0 ? 0 : INF;
	} else {
		int& ans = dp[pos][curr_xor];
		
		if (ans == -1) {
			ans = INF;
			
			for (int i = 0; i <= MAX_ADD; i++) {
				ans = min(ans, i + func(pos + 1, curr_xor ^ (A[pos] + i), A));
			}			
		}
		
		return ans;
	}
}
int EllysNimDiv2::getMin(vector <int> A) {
	memset(dp, -1, sizeof(dp));
	
	return func(0, 0, A);
}

//Powered by [KawigiEdit] 2.0!
