// Submitted - 2015-06-12 04:52:55
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

class FallingSand {
public:
	vector <string> simulate(vector <string>);
};

vector <string> FallingSand::simulate(vector <string> board) {
	int N = (int) board.size();
	int M = (int) board[0].size();

	while (1) {
		bool moved = false;

		for (int i = N - 1; i >= 0; i--) {
			for (int j = 0; j < M; j++) {
				if (board[i][j] == 'o' && i + 1 < N && board[i + 1][j] == '.') {
					swap(board[i][j], board[i + 1][j]);
					moved = true;
				}
			}
		}

		if (!moved) {
			break;
		}
	}
	return board;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!