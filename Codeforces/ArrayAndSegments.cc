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
const int INF = 80000008;

int N, M;
int L[400];
int R[400];

pair<int, int> tree[4 * MAXN];
int lazy[4 * MAXN];
int A[MAXN];

void goDown(int node, int l, int r) {
    if (lazy[node]) {
        tree[node].first += lazy[node];
        tree[node].second += lazy[node];

        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void build(int node, int l, int r) {
  if (l == r) {
    tree[node].first = A[l];
    tree[node].second = A[l];
    lazy[node] = 0;
  } else {
    int m = (l + r) / 2;

    build(2 * node, l, m);
    build(2 * node + 1, m + 1, r);

    tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
    tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
    lazy[node] = 0;
  }
}

pair<int, int> query(int node, int l, int r, int bl, int br) {
  goDown(node, l, r);
  if (l >= bl && r <= br) {
    return make_pair(tree[node].first, tree[node].second);
  } else if (l > br || r < bl) {
    return make_pair(INF, -INF);
  } else {
    int m = (l + r) / 2;

    pair<int, int> a = query(2 * node, l, m, bl, br);
    pair<int, int> b = query(2 * node + 1, m + 1, r, bl, br);

    return make_pair(min(a.first, b.first), max(a.second, b.second));
  }
}

void update(int node, int l, int r, int bl, int br, long long value) {
  goDown(node, l, r);
  if (l > r) {
    return;
  } else if (l > br || r < bl) {
    return;
  } else if (l >= bl && r <= br) {
    lazy[node] += value;
    goDown(node, l, r);
  } else {
    int m = (l + r) / 2;

    update(2 * node, l, m, bl, br, value);
    update(2 * node + 1, m + 1, r, bl, br, value);

    tree[node].first = min(tree[2 * node].first, tree[2 * node + 1].first);
    tree[node].second = max(tree[2 * node].second, tree[2 * node + 1].second);
  }
}


int main(void) {
  cin >> N >> M;

  vector<pair<int, int> > sorter;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sorter.push_back(make_pair(A[i], i));
  }

  sort(sorter.begin(), sorter.end());

  build(1, 0, N - 1);
  pair<int, int> nq = query(1, 0, N - 1, 0, N - 1);

  int ans = nq.second - nq.first;
  vector<int> done;

  for (int i = 0; i < M; i++) {
    cin >> L[i] >> R[i];
  }

  for (int i = 0; i < min(5000, N); i++) {
    build(1, 0, N - 1);
    vector<int> used;

    for (int j = 0; j < M; j++) {
      if (sorter[i].second >= L[j] - 1
          && sorter[i].second <= R[j] - 1) {
        continue;
      }

      used.push_back(j + 1);
      update(1, 0, N - 1, L[j] - 1, R[j] - 1, -1);
    }

    pair<int, int> nq = query(1, 0, N - 1, 0, N - 1);
    int local_ans = nq.second - nq.first;

    if (local_ans >= ans) {
      done = used;
      ans = local_ans;
    }
  }

  cout << ans << endl;
  cout << done.size() << endl;

  for (int i = 0; i < (int) done.size(); i++) {
    cout << done[i] << " ";
  }
  cout << "\n";

  return 0;
}
