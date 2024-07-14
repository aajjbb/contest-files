// 12-09-2013 18:27:28+01:00	Submit	aajjbb	250	248.53
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

class VowelLatin {
public:
	string translate(string);
};

bool vowel(char c) {
	c = tolower(c);

	if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;

	return false;
}

string VowelLatin::translate(string word) {
	int i;
	int N = (int) word.size();

	string ans = "", op = "";

	for (i = 0; i < N; i++) {
		if (vowel(word[i])) {
			op += word[i];
		} else {
			ans += word[i];
		}
	}

	return ans + op;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!