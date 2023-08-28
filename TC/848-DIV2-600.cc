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


class DinnerTable {
public:
	long long fits(long long piece_size, long long total_size) {
		if (piece_size > total_size) return 0;

		return total_size - piece_size + 1;
	}

	long long count(int R, int C, int L, int N) {
		long long ans = 0LL;
		map<int, vector<int>> map_r, map_c;

		for (long long i = 0; i < N; i++) {
			long long r = (4LL * i * i + 7 * i) % R;
			long long c = (i * i * i + 8 * i + 13) % C;

			map_r[r].push_back(c);
			map_c[c].push_back(r);
		}

		for (auto& [key, pieces] : map_r) {
			sort(pieces.begin(), pieces.end());

			int last_piece = 0;

			for (int i = 0; i < pieces.size(); i++) {
				//cerr << pieces[i] << " " << last_piece << " "  << fits(L, pieces[i] - last_piece) << endl;
				ans += fits(L, pieces[i] - last_piece);
				last_piece = pieces[i] + 1;
			}
			//cerr << C << " " << last_piece << " "  << fits(L, C - last_piece) << endl;
			ans += fits(L, C - last_piece);
		}
		//cerr << fits(L, C) << " " << (R -  map_r.size()) << endl;
		ans += fits(L, C) * (long long) (R - map_r.size());

		for (auto& [key, pieces] : map_c) {
			sort(pieces.begin(), pieces.end());

			int last_piece = 0;

			for (int i = 0; i < pieces.size(); i++) {
				//cerr << pieces[i] << " " << last_piece << " "  << fits(L, pieces[i] - last_piece) << endl;
				ans += fits(L, pieces[i] - last_piece);
				last_piece = pieces[i] + 1;
			}
			//cerr << R << " " << last_piece << " "  << fits(L, R - last_piece) << endl;
			ans += fits(L, R - last_piece);
		}
		//cerr << fits(L, R) << " " << (C -  map_c.size()) << endl;
		ans += fits(L, R) * (long long) (C - map_c.size());

		return ans;
	}
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!