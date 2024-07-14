// 01-22-2016 01:48:43+01:00	Submit	aajjbb	250	248.11
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

class TitleString {
public:
	string toFirstUpperCase(string);
};

string TitleString::toFirstUpperCase(string title) {
	for (int i = 0; i < (int) title.size(); i++) {
		if (isalpha(title[i]) and (i == 0 or title[i - 1] == ' ')) {
			title[i] = 'A' + (title[i] - 'a');
		}
	}

	return title;
}

//Powered by [KawigiEdit] 2.0!
