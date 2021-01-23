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

class AlicesBirthday {
public:
	vector <int> partition(int);
};


vector <int> AlicesBirthday::partition(int k) {
	int a = 0, b = 1;
	vector<int> fib(k);
	int sum = 0;

	for (int i = 0; i < k; i++) {
		sum += b;
		fib[i] = b;

		cout << sum << endl;

		int c = a + b;
		a = b;
		b = c;
	}

	if (sum % 2 != 0) {
		return {-1};
	}

	vector<int> ans;
	int goal = sum / 2;

	for (int i = k - 1; i >= 0; i--) {
		if (goal > 0 && goal - fib[i] >= 0) {
			goal -= fib[i];
			ans.push_back(i + 1);
		}
	}

	if (goal != 0) {
		return {-1};
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
