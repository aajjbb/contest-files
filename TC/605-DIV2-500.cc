// Submitted 2023-08-28 16:22:02
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;


class AlienAndGame {
public:
	int getNumber(vector <string> board) {
		const int n = board.size();
		const int m = board[0].size();

		for (int sz = min(n, m); sz >= 2; sz--) {
			for (int i = 0; i < n - sz + 1; i++) {
				for (int j = 0; j < m - sz + 1; j++) {
					bool valid = true;
					for (int k = i; k < i + sz; k++) {
						int b = 0;
						int w = 0;
						for (int l = j; l < j + sz; l++) {
							//cout << k << " " << l << endl;
							if (board[k][l] == 'B') {
								b += 1;
							} else {
								w += 1;
							}
						}
						if (min(b, w) > 0) {
							valid = false;
						}
					}
					//cout << valid << endl;
					if (valid) {
						return sz * sz;
					}
				}
			}
		}

		return 1;
	}
};

<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!