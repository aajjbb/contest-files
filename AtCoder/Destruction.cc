#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

//Kruskal Algorithm
struct edge {
    int from, to, cost;
    edge() {}
    edge(int from, int to, int cost): from(from), to(to), cost(cost) {};

    bool operator<(const edge& e) const {
		return cost < e.cost;
    }
};
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

int main(void) {
  int N, M;
  cin >> N >> M;

  vector<edge> edges;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    edges.push_back(edge(a, b, c));
  }

  sort(edges.begin(), edges.end());

  long long ans = 0;
  UnionFind u(N + 1);

  for(int i = 0; i < M; i++) {
    if(!u.find(edges[i].from, edges[i].to)) {
      u.unite(edges[i].from, edges[i].to);
    } else {
      //cout << edges[i].from << " " << edges[i].to << " " << edges[i].cost << endl;
      ans += max(0, edges[i].cost);
    }
  }

  cout << ans << endl;

  return 0;
}
