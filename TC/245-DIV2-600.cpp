// 10-01-2014 18:18:31+01:00	Submit	aajjbb	600	342.04
#include <bits/stdc++.h>

using namespace std;

class Flush {
public:
	double size(vector <int>, int);
};

const int MAXN = 13 * 4 + 2;

long long C[MAXN][MAXN];

void build(void) {
	C[0][0] = 1LL;

	for(int i = 1; i < MAXN; i++) {
	    C[i][0] = 1LL;
    	C[i][i] = 1LL;

	    for (int j = 1; j < i; j++) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
    }
}

double Flush::size(vector <int> suits, int number) {
	build();

	int sum = accumulate(suits.begin(), suits.end(), 0);
	double prob = 0.0;

	for (int i = 0; i <= suits[0]; i++) {
		for (int j = 0; j <= suits[1]; j++) {
			for (int k = 0; k <= suits[2]; k++) {
				for (int l = 0; l <= suits[3]; l++) {
					if (i + j + k + l == number) {
						int flush = max(i, max(j, max(k, l)));

						double un = C[suits[0]][i] * C[suits[1]][j] * C[suits[2]][k] * C[suits[3]][l];
						double ap = C[sum][number];

						prob += flush * (un / ap);
					}
				}
			}
		}
	}

	return prob;
}

//Powered by [KawigiEdit] 2.0!
