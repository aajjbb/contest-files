// 09-11-2012 12:51:07+01:00	Submit	aajjbb	500	416.70
#line 74 "ATaleOfThreeCities.cpp"
/*
 aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

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

struct edge {
    int from, to;
    double cost;
    edge() {}
    edge(int from, int to, double cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
		return cost < e.cost;
    }
};

struct ATaleOfThreeCities {
	double connect(vector <int> ax, vector <int> ay, vector <int> bx, vector <int> by, vector <int> cx, vector <int> cy) {
		int i, j, count = 0;
		double minimal = 0.0;
		vector<edge> ve;
		REP(i, ax.size()) {
			REP(j, bx.size()) {
				ve.push_back(edge(0, 1, dist((double)ax[i], (double)ay[i], (double)bx[j], (double)by[j])));
			}
		}
		REP(i, ax.size()) {
			REP(j, cx.size()) {
				ve.push_back(edge(0, 2, dist((double)ax[i], (double)ay[i], (double)cx[j], (double)cy[j])));
			}
		}
		REP(i, bx.size()) {
			REP(j, cx.size()) {
				ve.push_back(edge(1, 2, dist((double)bx[i], (double)by[i], (double)cx[j], (double)cy[j])));
			}
		}
		UnionFind uf(3);
		sort(ve.begin(), ve.end());
		REP(i, ve.size()) {
			if(!uf.find(ve[i].from, ve[i].to)) {
				count += 1;
				uf.unite(ve[i].from, ve[i].to);
				minimal += ve[i].cost;
			}
			if(count == 2) break;
		}
		return minimal;
	}
	double dist(double xa, double ya, double xb, double yb) {
		return (double) hypot(xa - xb, ya - yb);
	}
};

<%:testing-code%>
// Powered by FileEdit