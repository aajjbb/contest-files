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

int N;
vector<pair<int, int> > tree[MAXN];
int label[MAXN];
int ll, lr;

int get_label() {
  int dl = ll;
  int dr = N - 2 - lr;

  if (dl <= dr) {
    ll += 1;
    return ll - 1;
  } else {
    lr -= 1;
    return lr + 1;
  }
}

void dfs(int node, int parent) {
  for (int i = 0; i < tree[node].size(); i++) {
    int next = tree[node][i].first;
    int edge_id = tree[node][i].second;

    if (next == parent) {
      continue;
    }
    
    //cout << edge_id << " " << label[edge_id] << endl;
    dfs(next, node);

    label[edge_id] = get_label();
  }
}

int main(void) {
  cin >> N;

  for (int i = 0; i < N - 1; i++) {
    int a, b;

    cin >> a >> b;

    a -= 1;
    b -= 1;
    
    // second to identify the edge
    tree[a].push_back(make_pair(b, i));
    tree[b].push_back(make_pair(a, i));
  }

  ll = 0;
  lr = N - 2;
  
  dfs(0, -1);

  for (int i = 0; i < N - 1; i++) {
    cout << label[i] << "\n";
  }
  
  return 0;
}
