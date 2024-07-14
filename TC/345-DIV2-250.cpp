// 11-20-2013 15:40:51+01:00	Submit	aajjbb	250	234.71
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

class Trekking {
public:
	int findCamps(string, vector <string>);
};

int Trekking::findCamps(string trail, vector <string> plans) {
	int i;
	int j;
	int ans = INT_MAX / 2;

	for (i = 0; i < (int) plans.size(); i++) {
		bool ok = true;
		int night = 0;
		for (j = 0; j < (int) trail.size(); j++) {
			if (trail[j] == '^' && plans[i][j] == 'C') ok = false;
			if (plans[i][j] == 'C') night++;
		}
		if (ok) {
			chmin(ans, night);
		}
	}
	return ans == INT_MAX / 2 ? -1 : ans;
}

//Powered by [KawigiEdit] 2.0!

