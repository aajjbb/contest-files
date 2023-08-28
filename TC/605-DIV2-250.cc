// Submitted 2014-01-21 22:23:02
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

class AlienAndPassword {
public:

	int getNumber(string);
};

int AlienAndPassword::getNumber(string S) {
	set<string> s;

	for (int i = 0; i < (int) S.size(); i++) {
		s.insert(S.substr(0, i) + S.substr(i + 1));
	}

	return (int) s.size();
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!