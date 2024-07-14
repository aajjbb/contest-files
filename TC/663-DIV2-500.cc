// Submitted - 2015-08-12 03:31:46
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

class ABBA {
public:
	string canObtain(string, string);
};

string ABBA::canObtain(string initial, string target) {
	while (target.size() > initial.size()) {
		char last = target.back();

		target = target.substr(0, target.size() - 1);

		if (last == 'B') {
			reverse(target.begin(), target.end());
		}

	}
	return initial == target ? "Possible" : "Impossible";
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!