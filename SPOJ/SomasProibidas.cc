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
const int MAXM = 110;

int cards[MAXN];
int forbid[MAXM];
vector<int> graph[MAXN];
int color[MAXN];

bool dfs(int node, int c) {
  color[node] = c;

  bool ans = true;

  for (int i = 0; i < graph[node].size(); i++) {
    int next = graph[node][i];

    if (color[next] == c) {
      ans = false;
    } else if (color[next] == -1) {
      ans &= dfs(next, 1 - c);
    }
  }

  return ans;
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  unordered_map<long long, int> pos_map;

  for (int i = 0; i < N; i++) {
    cin >> cards[i];

    pos_map[cards[i]] = i;
    color[i] = -1;
  }

  for (int i = 0; i < M; i++) {
    cin >> forbid[i];
  }

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      long long rev = forbid[i] - cards[j];

      if (rev > 0 && pos_map.find(rev) != pos_map.end()) {
	if (pos_map[rev] == j) {
	  continue;
	}
	graph[j].push_back(pos_map[rev]);
	graph[pos_map[rev]].push_back(j);
      }
    }
  }

  bool valid = true;

  for (int i = 0; i < N; i++) {
    if (color[i] != -1) {
      continue;
    }
    valid &= dfs(i, 0);
  }

  if (!valid) {
    cout << "-1\n-1\n";
  } else {
    vector<int> va, vb;

    for (int i = 0; i < N; i++) {
      if (color[i] <= 0) {
	va.push_back(cards[i]);
      } else {
	vb.push_back(cards[i]);
      }
    }

    sort(va.begin(), va.end());
    sort(vb.begin(), vb.end());

    cout << va.size();

    for (int i = 0; i < va.size(); i++) {
      cout << " " << va[i];
    }
    cout << "\n";
    cout << vb.size();
    for (int i = 0; i < vb.size(); i++) {
      cout << " " << vb[i];
    }
    cout << "\n";
  }

  return 0;
}
