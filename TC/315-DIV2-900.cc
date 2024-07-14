// 12-07-2011 16:15:02+01:00	Submit	aajjbb	900	270.00
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

class KidsGame {
	public:
	int kthKid(int n, int m, int k) {
		return rec(n, m, k);
	}

	int rec(int n, int m, int k) {
		int pos = m % n;
		if(pos == 0) {
			pos = n;
		}
		if(k < pos) {
			return rec(n - 1, m, n - pos + k) + 1;
		}
		if(k > pos) {
			return rec(n - 1, m, k - pos) + 1;
		}
		return 1;
	}
};


<%:testing-code%>
// Powered by FileEdit