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

const int MAXN = 100005;
const int MAX_LOG = 20;

int T;
vector<int> tree[MAXN];
int parent[MAXN][MAX_LOG];

void dfs(int node, int p) {
  //cerr << node << " " << p << endl;
  if (p != -1) {
    parent[node][0] = p;
    for (int i = 1; i < MAX_LOG; i++) {
      parent[node][i] = parent[parent[node][i - 1]][i - 1];
      //cerr << node << " " << i << " " << parent[node][i] << endl;
    }
  }

  for (int i = 0; i < tree[node].size(); i++) {
    int next = tree[node][i];

    dfs(next, node);
  }
}

void add_node(int node, int p) {
  tree[p].push_back(node);

  parent[node][0] = p;
  for (int i = 1; i < MAX_LOG; i++) {
    parent[node][i] = parent[parent[node][i - 1]][i - 1];
    //cerr << node << " " << i << " " << parent[node][i] << endl;
  }
}

void remove_node(int node) {
  int p = parent[node][0];

  tree[p].erase(find(tree[p].begin(), tree[p].end(), node));

  for (int i = 0; i < MAX_LOG; i++) {
    parent[node][i] = 0;
  }
}

int get_parent(int node, int level) {
  int answer = node;

  for (int i = MAX_LOG - 1; i >= 0; i--) {
    //cout << answer << " " << i << " " << parent[answer][i] << endl;
    if (level - (1 << i) >= 0) {
      answer = parent[answer][i];
      level -= (1 << i);
    }
  }

  assert(level == 0);

  return answer;
}

int main(void) {
  cin >> T;

  for (int t = 0; t < T; t++) {
    int P, Q;
    int root = 0;

    cin >> P;

    for (int i = 0; i < MAXN; i++) {
      tree[i].clear();
      for (int j = 0; j < MAX_LOG; j++) {
        parent[i][j] = 0;
      }
    }

    for (int i = 0; i < P; i++) {
      int x, y;

      cin >> x >> y;

      if (y == 0) {
        root = x;
      }

      tree[y].push_back(x);
    }

    dfs(root, -1);

    cin >> Q;

    for (int q = 0; q < Q; q++) {
      int type;

      cin >> type;

      if (type == 0) {
        int x, y;

        cin >> y >> x;

        add_node(x, y);
      } else if (type == 1) {
        int x;

        cin >> x;

        remove_node(x);
      } else {
        int x, k;

        cin >> x >> k;

        int p = get_parent(x, k);

        cout << p << "\n";
      }
    }

  }
  return 0;
}
