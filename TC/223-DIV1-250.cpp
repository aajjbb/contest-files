// 12-09-2013 13:40:26+01:00	Submit	aajjbb	250	202.25
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

class QuizShow {
public:
	int wager(vector <int>, int, int);
};

int QuizShow::wager(vector <int> scores, int wager1, int wager2) {
	int i;
	int j;
	int k;

	int ot;
	int best = 0, ans = 0;

	for (ot = 0; ot <= scores[0]; ot++) {
		int fav = 0;

		for (i = -1; i <= 1; i += 2) {
			for (j = -1; j <= 1; j += 2) {
				for (k = -1; k <= 1; k += 2) {
					int my = scores[0] + ot * i;

					if (my > scores[1] + j * wager1 && my > scores[2] + k * wager2) {
						fav += 1;
					}
				}
			}
		}
		if (fav > best) {
			best = fav;
			ans = ot;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
