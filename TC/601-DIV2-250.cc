// 2013-12-22 19:04:53

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

class WinterAndMandarins {
public:
	int getNumber(vector <int>, int);
};

int WinterAndMandarins::getNumber(vector <int> bags, int K) {
	int i;
	
	int N = (int) bags.size();
	
	int best = 1000000005;
	
	sort(bags.begin(), bags.end());
	
	for (i = 0; i < N - K + 1; i++) {
		int curr = bags[i + K - 1] - bags[i];
		
		if (curr < best) best = curr;
		
	}
	
	return best;
}

//Powered by [KawigiEdit] 2.0!