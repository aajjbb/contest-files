// 2015-06-22T04:27:43+01:00
#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

class InterestingDigits {
public:
	vector <int> digits(int);
};

vector<int> rep(int x, int base) {
	vector<int> ans;

	while (x > 0) {
		ans.push_back(x % base);
		x /= base;
	}

	return ans;
}

bool func(int digit, int base) {
	for (int i = 1; ; i++) {
		vector<int> curr = rep(digit * i, base);

		if (curr.size() > 3) break;

		if (accumulate(curr.begin(), curr.end(), 0) % digit != 0) {
			return false;
		}
	}
	return true;
}

vector <int> InterestingDigits::digits(int base) {
	vector<int> ans;

	for (int i = 2; i < base; i++) {
		if (func(i, base)) {
			ans.push_back(i);
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
