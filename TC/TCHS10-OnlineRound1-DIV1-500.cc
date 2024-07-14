// 2013-12-06T23:37:37+01:00
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

class TheSequencesLevelTwo {
public:

	vector <int> find(vector <int>);
};

vector <int> TheSequencesLevelTwo::find(vector <int> sequence) {
	int i;
	int N = (int) sequence.size();

	sort(sequence.begin(), sequence.end());

	vector<int> ans;
	vector<bool> mark(N, false);

	for (i = 0; i < N; i++) if (!mark[i]) {
		ans.push_back(sequence[i]);

		int next = (i == 0 ? i + 2 : i + 3);

		if (next < N) {
			ans.push_back(sequence[next]);
			mark[next] = true;
		}
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!