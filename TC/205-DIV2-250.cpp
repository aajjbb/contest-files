// 12-04-2013 20:25:18+01:00	Submit	aajjbb	250	248.25
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

using namespace std;

typedef long long Int;
typedef unsigned uint;

class Average {
public:
	int belowAvg(vector <int>, vector <int>);
};

int Average::belowAvg(vector <int> math, vector <int> verbal) {
	int i;
	int ans = 0;
	int N = (int) math.size();

	double ave = (double) (accumulate(math.begin(), math.end(), 0) + accumulate(verbal.begin(), verbal.end(), 0)) / (double) N;

	for (i = 0; i < N; i++) {
		if (math[i] + verbal[i] < ave) ans += 1;
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
