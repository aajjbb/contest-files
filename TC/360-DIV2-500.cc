// 12-19-2013 16:02:37+01:00	Submit	aajjbb	500	307.20
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

class SumOfSelectedCells {
public:
	string hypothesis(vector <string>);
};

const int INF = 1001010;

set<int> sum;

int table[30][30];

int dpA[(1 << 20)];
int dpB[(1 << 20)];

int N;
int M;

int funcA(int row, int mask) {
	if (row == N || mask == (1 << M) - 1) {
		return 0;
	} else {
		int& ans = dpA[mask];

		if (ans == -1) {
			int i;

			ans = 0;

			for (i = 0; i < M; i++) if (!(mask & (1 << i))) {
				ans = max(ans, table[row][i] + funcA(row + 1, mask | (1 << i)));
			}
		}

		return ans;
	}
}

int funcB(int row, int mask) {
	if (row == N || mask == (1 << M) - 1) {
		return 0;
	} else {
		int& ans = dpB[mask];

		if (ans == -1) {
			int i;

			ans = INF;

			for (i = 0; i < M; i++) if (!(mask & (1 << i))) {
				ans = min(ans, table[row][i] + funcB(row + 1, mask | (1 << i)));
			}
		}

		return ans;
	}
}
string SumOfSelectedCells::hypothesis(vector <string> _table) {
	int i;

	N = (int) _table.size();

	for (i = 0; i < N; i++) {
		istringstream ss(_table[i]);
		int tp, j = 0;

		for ( ; ss >> tp; ) {
			table[i][j++] = tp;
		}

		M = j;
	}
	for (i = 0; i < (1 << N); i++) {
		dpA[i] = dpB[i] = -1;
	}

	int A = funcA(0, 0);
	int B = funcB(0, 0);

	if (A == B) {
		return "CORRECT";
	} else {
		return "INCORRECT";
	}
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!