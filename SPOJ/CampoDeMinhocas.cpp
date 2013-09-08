#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;


int readInt () {
	bool minus = false;
	int result = 0;
	char ch;

	ch = getchar();

	while (1) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') {
	    minus = true;
    } else {
        result = ch-'0';
    }

	while (1) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result * 10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}

const int MAXN = 1003;

int N, M, T = 1;
int sp[MAXN][MAXN];
int dp[MAXN][MAXN][3];

const int INF = 1010010010;

int func(int i, int j, int kind) {
    if (i == N - 1 && j == M - 1) {
        return sp[i][j];
    }
    if (dp[i][j][kind] != INF) {
        return dp[i][j][kind];
    }

    int& ans = dp[i][j][kind] = -(INF);

    if (i + 1 < N) {
        chmax(ans, sp[i][j] + func(i + 1, j, 0));
    }
    if (j + 1 < M && kind != 2) {
        chmax(ans, sp[i][j] + func(i, j + 1, 1));
    }
    if (j - 1 >= 0 && kind != 1) {
        chmax(ans, sp[i][j] + func(i, j - 1, 2));
    }
    return ans;
}

int main(void) {
    int i, j, k;

    for ( ; ; ) {
        N = readInt();
        M = readInt();

        if (N + M == 0) break;

        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) {
                sp[i][j] = readInt();
                for (k = 0; k < 3; k++) {
                    dp[i][j][k] = INF;
                }
            }
        }
        printf("Teste %d\n%d\n\n", T++, func(0, 0, 0));
    }
    return 0;
}
