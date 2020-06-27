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

class AqaAsadiPlays {
public:
	int getMin(vector <int>);
};

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

int AqaAsadiPlays::getMin(vector <int> A) {
	const int n = A.size();
	
	sort(A.rbegin(), A.rend());
	
	int ans = -1;
	int total_gcd = A[0];
	
	
	for (int i = 0; i < n - 1; i++) {
		total_gcd = gcd(total_gcd, A[i]);
		
		if (total_gcd > A[i + 1]) {
			ans = i + 1;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
