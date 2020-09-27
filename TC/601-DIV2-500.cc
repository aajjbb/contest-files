// 2020-09-27 - 13:46 BST - 491.73

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

class WinterAndCandies {
public:
	int getNumber(vector <int>);
};

int WinterAndCandies::getNumber(vector <int> type) {
	vector<int> cnt(51);
	
	for (int i = 0; i < type.size(); i++) {
		cnt[type[i]] += 1;
	}
	
	long long ans = 0;
	long long acc = 1;
	
	for (int i = 1; i <= 50; i++) {
		acc *= cnt[i];
		ans += acc;
	}
	
	return (int) ans;
}

//Powered by [KawigiEdit] 2.0!