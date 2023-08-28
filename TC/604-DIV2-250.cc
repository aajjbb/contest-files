// Submitted 2014-01-11 22:05:12
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

class FoxAndWord {
public:

	int howManyPairs(vector <string>);
};

bool func(string a, string b) {
	int N = (int) a.size();

	for (int i = 1; i < N; i++) {
		string f = a.substr(0, i);
		string s = a.substr(i, N - i);

		if (s + f == b) return true;
	}

	return false;
}

int FoxAndWord::howManyPairs(vector <string> words) {
	int N = (int) words.size();
	int ans = 0;


	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (func(words[i], words[j])) {
				ans += 1;
			}
		}
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!