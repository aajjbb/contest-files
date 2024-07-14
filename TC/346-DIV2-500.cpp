// 08-30-2015 18:01:34+01:00	Submit	aajjbb	500	491.00
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

class CommonMultiples {
public:
	int countCommMult(vector <int>, int, int);
};

int CommonMultiples::countCommMult(vector <int> a, int lower, int upper) {
	int N = a.size();
	long long val = a[0];

	for (int i = 1; i < N; i++) {
		val = lcm(val, (long long) a[i]);
	}

	return upper / val - (lower - 1) / val;
}

//Powered by [KawigiEdit] 2.0!
