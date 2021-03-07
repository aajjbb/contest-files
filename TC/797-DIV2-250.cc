#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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


class BuyOneGetOneFree {
public:
	int buy(vector <int> prices) {
		int ans = 0;

		sort(prices.rbegin(), prices.rend());

		for (int i = 0; i < prices.size(); i += 2) {
			ans += prices[i];
		}

				
		return ans;	
	}
};


//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
