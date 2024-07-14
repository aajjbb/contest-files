#include <bits/stdc++.h>

using namespace std;

class TileCutting {
public:
	int cuts(vector <string>);
};

int TileCutting::cuts(vector <string> layout) {
	int N = (int) layout.size();
	int M = (int) layout[0].size();

	int sq = 0;
	int el = 0;
	int hf = 0;

	int ans = 0;

	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < M - 1; j++) {
			if (i % 2 == 0 && j % 2 == 0) {
				int empty = 0;

				for (int k = 0; k < 2; k++) {
					for (int l = 0; l < 2; l++) {
						if (layout[i + k][j + l] == '.') {
							empty += 1;
						}
					}
				}
				if (empty == 1) {
					sq += 1;
				} else if (empty == 3) {
					el += 1;
				} else if (empty == 2) {
					if ((layout[i][j] == '.' && layout[i + 1][j + 1] == '.') || (layout[i + 1][j] == '.' && layout[i][j + 1] == '.')) {
						sq += 2;
					} else {
						hf += 1;
					}
				}
			}
		}
	}

	while (el >= 1 && sq >= 1) {
		ans += 2;
		el -= 1;
		sq -= 1;
	}

	while (hf >= 2) {
		ans += 2;
		hf -= 2;
	}

	if (sq != 0) {
		while (hf > 0 && sq >= 2) {
			ans += 3;
			hf -= 1;
			sq -= 2;
		}
		while (hf > 0 && sq >= 1) {
			ans += 3;
			hf -= 1;
			sq -= 1;
		}
		if (hf == 1) {
			ans += 2;
			hf -= 1;
		}
		while (sq >= 4) {
			ans += 4;
			sq -= 4;
		}
		if (sq != 0) {
			ans += sq + 1;
		}
	} else {
		ans += (hf + el) * 2;
	}

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!