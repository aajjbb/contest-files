// 2011-11-01T10:19:04+01:00
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

class MNS {
	public:
	int combos(vector <int> numbers)  {
		int count = 0;

		sort(numbers.begin(), numbers.end());

		do {
			if(valid(numbers) == true) {
				count++;
			}
		} while(next_permutation(numbers.begin(), numbers.end()));
		return count;
	}
	bool valid(vector <int> n) {
		int r1 = (n[0] + n[1] + n[2]);
		int r2 = (n[3] + n[4] + n[5]);
		int r3 = (n[6] + n[7] + n[8]);
		int c1 = (n[0] + n[3] + n[6]);
		int c2 = (n[1] + n[4] + n[7]);
		int c3 = (n[2] + n[5] + n[8]);

		return r1 == r2 && r2 == r3 && r3 == c1 && c1 == c2 && c2 == c3;
	}
};


<%:testing-code%>
// Powered by FileEdit