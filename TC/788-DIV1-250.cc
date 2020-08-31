// 2020-08-30 16:29
#include <vector>
#include <list>
#include <map>
#include <set>
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

class RailwayMaster {
public:
	int maxProfit(int, int, int, vector <int>, vector <int>, vector <int>);
};

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

int RailwayMaster::maxProfit(int N, int M, int K, vector <int> a, vector <int> b, vector <int> v) {
	vector<pair<int, pair<int, int>>> edges(M);
	UnionFind uf(N);

	for (int i = 0; i < M; i++) {
		edges[i] = make_pair(v[i], make_pair(a[i], b[i]));
	}

	sort(edges.begin(), edges.end());

	vector<int> leftover_costs;

	for (int i = 0; i < M; i++) {
		int na = edges[i].second.first;
		int nb = edges[i].second.second;
		int cost = edges[i].first;

		if (!uf.find(na, nb)) {
			uf.unite(na, nb);
		} else {
			leftover_costs.push_back(cost);
		}
	}

	int ans = 0;

	reverse(leftover_costs.begin(), leftover_costs.end());

	for (int i = 0; i < min(K, (int) leftover_costs.size()); i++) {
		ans += leftover_costs[i];
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
