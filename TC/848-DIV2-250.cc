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


class MissingPuzzlePiece {
public:
	string to_piece(int r, int c) {
		char rc = 'A' + r - 1;

		return rc + to_string(c);
	}
	string identify(int R, int C, vector <string> pieces) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				string p = to_piece(i, j);

					if (find(pieces.begin(), pieces.end(), p) == pieces.end()) {
						return p;
					}
			}
		}
		return "";
	}
};

<%:testing-code%>
//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!