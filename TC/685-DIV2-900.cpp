// Submitted - 2018-04-02 01:50:18
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
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//Union Find
struct UnionFind {
    int N, *id, *sz;

    UnionFind(int _N) {
        id = new int[_N];
        sz = new int[_N];
        for(int i = 0; i < _N; i++) {
            id[i] = i;
            sz[i] = 1;
        }
        N = _N;
    }
    int root(int i) {
        while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
    }
    bool find(int p, int q) {
        return root(p) == root(q);
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
    }
};

class RGBTree {
public:
	string exist(vector <string> G) {
		const int N = G.size();
		const int K = (N - 1) / 3;

		vector<pair<int, int> > edges[3];

		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				if (G[i][j] == 'R') {
					edges[0].push_back(make_pair(i, j));
				} else if (G[i][j] == 'G') {
					edges[1].push_back(make_pair(i, j));
				} else if (G[i][j] == 'B') {
					edges[2].push_back(make_pair(i, j));
				}
			}
		}
		const int SR = edges[0].size();
		const int SG = edges[1].size();
		const int SB = edges[2].size();

		for (int a = 0; a < (1 << SR); a++) {
			if (__builtin_popcount(a) != K) continue;
			for (int b = 0; b < (1 << SG); b++) {
				if (__builtin_popcount(b) != K) continue;
				for (int c = 0; c < (1 << SB); c++) {
					if (__builtin_popcount(c) != K) continue;

					UnionFind uf(N);
					int cnt = 0;

					for (int i = 0; i < SR; i++) {
						if (!(a & (1 << i))) continue;

						int fa = edges[0][i].first;
						int fb = edges[0][i].second;

						if (!uf.find(fa, fb)) {
							cnt += 1;
							uf.unite(fa, fb);
						}
					}

					for (int i = 0; i < SG; i++) {
						if (!(b & (1 << i))) continue;

						int fa = edges[1][i].first;
						int fb = edges[1][i].second;

						if (!uf.find(fa, fb)) {
							cnt += 1;
							uf.unite(fa, fb);
						}
					}


					for (int i = 0; i < SB; i++) {
						if (!(c & (1 << i))) continue;

						int fa = edges[2][i].first;
						int fb = edges[2][i].second;

						if (!uf.find(fa, fb)) {
							cnt += 1;
							uf.unite(fa, fb);
						}
					}

					if (cnt == N - 1) {
						return "Exist";
					}
				}
			}
		}
		return "Does not exist";
	}
};

//Powered by KawigiEdit-pf 2.3.0!
