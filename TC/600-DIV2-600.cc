// Submitted 2023-08-28 18:13:03

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

class ORSolitaireDiv2 {
public:
	int getMinimum(vector <int>, int);
};

const int INF = (1 << 30);
const int MAX_BITS = 31;

int ORSolitaireDiv2::getMinimum(vector <int> numbers, int goal) {
	const int n = numbers.size();
	int ans = INF;
	int curr_or = 0;
	vector<int> cnt(MAX_BITS + 2);

	for (int i = 0; i < n; i++) {
		if ((numbers[i] & goal) != numbers[i]) {
			continue;
		}
		for (int j = 0; j <= MAX_BITS; j++) {
			if (((1 << j) & numbers[i]) == 0) {
				continue;
			}
			cnt[j] += 1;
		}
		curr_or |= numbers[i];
	}

	if (curr_or != goal) {
		return 0;
	}

	for (int i = 0; i <= MAX_BITS; i++) {
		if (cnt[i] > 0) {
			ans = min(ans, cnt[i]);
		}
	}

	if (ans == INF) {
		ans = 0;

	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!