// Submitted 2014-01-11 22:39:46
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

class PowerOfThreeEasy {
public:

	string ableToGet(int, int);
};

int x, y;

bool func(int id, int xx, int yy) {
	if (xx == x && yy == y) {
		return true;
	}

	if (xx > x || yy > y) return false;

	if (func(id + 1, xx + (int) pow(3.0, id), yy) || func(id + 1, xx, yy + (int) pow(3.0, id))) return true;

	return false;
}

string PowerOfThreeEasy::ableToGet(int x, int y) {
	::x = x;
	::y = y;
	return func(0, 0, 0) ? "Possible" : "Impossible";
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!