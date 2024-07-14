// 2016-07-22T04:45:52+01:00
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

class LibraryWorker {
public:
	int replaceBooks(vector <int>, int);
};

const int INF = INT_MAX / 5;

int dp[60][60];

int func(int pos, int used, int max_book, vector<int>& buff) {
	if (pos == (int) buff.size()) {
		return 00;
	} else if (used == max_book) {
		return 2 * buff[pos - 1] + func(pos + 1, 1, max_book, buff);
	} else {
		int& ans = dp[pos][used];

		if (ans == -1) {
			if (pos == (int) buff.size() - 1) {
				ans = func(pos + 1, 0, max_book, buff);
			} else {
				ans = 2 * buff[pos] + func(pos + 1, 0, max_book, buff);
			}
			ans = min(ans, func(pos + 1, used + 1, max_book, buff));
		}

		return ans;
	}
}

int LibraryWorker::replaceBooks(vector <int> books, int N) {
	vector<int> pos, neg;

	for (int i = 0; i < (int) books.size(); i++) {
		if (books[i] >= 0) {
			pos.push_back(books[i]);
		} else {
			neg.push_back(-books[i]);
		}
	}

	int ans = INF;

	int pe = 0;
	int ne = 0;

	sort(pos.begin(), pos.end());
	memset(dp, -1, sizeof(dp));
//	cout << func(0, 0, N, pos) << "\n";
	pe += func(0, 0, N, pos);

	sort(neg.begin(), neg.end());
	memset(dp, -1, sizeof(dp));
//	cout << func(0, 0, N, neg) <<" \n";
	ne += func(0, 0, N, neg);

	if (pos.empty()) pos.push_back(0);
	if (neg.empty()) neg.push_back(0);

	ans = min(ans, pe + ne + 2 * pos.back() + neg.back());
	ans = min(ans, pe + ne + 2 * neg.back() + pos.back());
	return ans;
}

//Powered by [KawigiEdit] 2.0!
