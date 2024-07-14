// 2024-05-26 20:15:03
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


class NumReverseEasy {
public:
	int rev(int arg) {
		int ans = 0;

		while (arg > 0) {
			ans = ans * 10 + (arg % 10);
			arg /= 10;
		}
		return ans;
	}
	long long getsum(int A, int B) {
		long long sum = 0;

		for (int i = A; i <= B; i++) {
			sum += max(i, rev(i));
		}

		return sum;
	}
};
<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
