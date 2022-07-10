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

class TaliluluCoffee {
public:
	int maxTip(vector <int>);
};

int TaliluluCoffee::maxTip(vector <int> tips) {
	int i;
	int N = (int) tips.size();
	int ans = 0;
	
	sort(tips.rbegin(), tips.rend());
	
	for (i = 0; i < N && tips[i] - i > 0; i++) {
		ans += tips[i] - i;
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!