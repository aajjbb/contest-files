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

class KingdomReorganization {
public:
	int getCost(vector <string>, vector <string>, vector <string>);
};

struct edge {
  int from, to, cost;
  edge() {}
  edge(int from, int to, int cost): from(from), to(to), cost(cost) {};

  bool operator<(const edge& e) const {
  return cost < e.cost;
  }
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

int edgeCost(char c) {
	if (isupper(c)) {
		return c - 'A';
	} else {
		return c - 'a' + 26;
	}
}

int KingdomReorganization::getCost(vector <string> kingdom, vector <string> build, vector <string> destroy) {
	const int N = kingdom.size();
	int build_cost = 0;
	
	UnionFind uf(N);
	
	// Deciding which roads to destroy.
	vector<edge> initial_graph;
	vector<edge> new_edges;
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (kingdom[i][j] == '0') {
				int cost = edgeCost(build[i][j]);
				new_edges.emplace_back(edge(i, j, cost));	
			} else {
				int cost = edgeCost(destroy[i][j]);
				initial_graph.emplace_back(edge(i, j, cost));
			}
		}				
	}
	
	sort(initial_graph.rbegin(), initial_graph.rend());
	
	for (int i = 0; i < initial_graph.size(); i++) {
		int a = initial_graph[i].from;
		int b = initial_graph[i].to;
		int cost = initial_graph[i].cost;
		
		if (uf.find(a, b)) {
			build_cost += cost;
		} else {
			uf.unite(a, b);
		}
	}
	
	//Now, adding the new roads.
	sort(new_edges.begin(), new_edges.end());
	
	for (int i = 0; i < new_edges.size(); i++) {
		int a = new_edges[i].from;
		int b = new_edges[i].to;
		int cost = new_edges[i].cost;
		
		if (!uf.find(a, b)) {
			build_cost += cost;
			uf.unite(a, b);
		}
	}
	
	return build_cost;
}

//Powered by [KawigiEdit] 2.0!