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

class RealTaskWithTwins {
public:
	vector <int> solve(vector <int>);
};

vector <int> RealTaskWithTwins::solve(vector <int> ages) {
	vector<int> cnt(201, 0);
	vector<int> ans = {0, 0};
	
	sort(ages.rbegin(), ages.rend());
	
	for (int i = 0; i < ages.size(); i++) {
		cnt[ages[i]] += 1;
		
		if (cnt[ages[i]] % 2 == 0) {
			ans[0] = max(ans[0], ages[i]);
			ans[1] += 1;
		}
	}
	
	for (int i = 0; i < ages.size(); i++) {	
		if (cnt[ages[i]] % 2 == 1) {
			ans[0] = max(ans[0], ages[i]);
			ans[1] += 1;
			break;
		}
	}
	
	return ans;	
}


//Powered by [KawigiEdit] 2.0!