#line 47 "MagicCube.cpp"
/*
 aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct MagicCube {
	int getScore(vector<int> nums) {
		int ans = func(nums);
		for(int i = 0; i < (int) nums.size(); i++) {
			for(int j = i + 1; j < (int) nums.size(); j++) {
				swap(nums[i], nums[j]);
				ans = min(ans, func(nums));
				swap(nums[i], nums[j]);
			}
		}
		return ans;
	}
	int func(vector<int> nums) {
		int m = INT_MIN, mi = INT_MAX;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				int A = 0, B = 0, C = 0;
				for(int k = 0; k < 3; k++) {
					A += nums[i*9+j*3+k];
					B += nums[j*9+k*3+i];
					C += nums[k*9+i*3+j];
				}
				m = max(m, A); m = max(m, B); m = max(m, C);
				mi = min(mi, A); mi = min(mi, B); mi = min(mi, C);
			}
		}
		return abs(m - mi);
	}
};

// Powered by FileEdit
