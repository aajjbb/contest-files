/*
ID: jeferso1
PROG: ttwo
LANG: C++
*/

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

const int MAX_RUNS = 10000000;
const int N = 10;

string S[N];
int dist[N][N][N][N];

// 0 = N
// 1 = E
// 2 = S
// 3 = W
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool is_valid(int i, int j) {
  return i >= 0 && j >= 0 && i < N && j < N && S[i][j] != '*';
}

pair<pair<int, int>, int> get_new(pair<int, int> pos, int dir) {
  int new_i = pos.first + dx[dir];
  int new_j = pos.second + dy[dir];

  if (is_valid(new_i, new_j)) {
    return make_pair(make_pair(new_i, new_j), dir);
  } else {
    int new_dir = (dir + 1) % 4;

    return make_pair(pos, new_dir);
  }
}

int main(void) {
  freopen("ttwo.in", "r", stdin);
  freopen("ttwo.out", "w", stdout);

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  pair<int, int> f_init, c_init;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (S[i][j] == 'F') {
	f_init = make_pair(i, j);
      }
      if (S[i][j] == 'C') {
	c_init = make_pair(i, j);
      }
    }
  }

  int runs = 0;
  int ans = 0;

  queue<pair<pair<pair<int, int>, int>, pair<pair<int, int>, int> > > q;
  q.push(make_pair(make_pair(f_init, 0), make_pair(c_init, 0)));

  while (!q.empty() && runs < MAX_RUNS) {
    pair<int, int> f_now = q.front().first.first;
    int f_dir = q.front().first.second;
    pair<int, int> s_now = q.front().second.first;
    int s_dir = q.front().second.second;
    q.pop();

    if (f_now == s_now) {
      ans = dist[f_now.first][f_now.second][s_now.first][s_now.second];
      break;
    }

    pair<pair<int, int>, int> new_f_result = get_new(f_now, f_dir);
    pair<pair<int, int>, int> new_s_result = get_new(s_now, s_dir);

    pair<int, int> new_f = new_f_result.first;
    int new_f_dir = new_f_result.second;
    pair<int, int> new_s = new_s_result.first;
    int new_s_dir = new_s_result.second;

    dist[new_f.first][new_f.second][new_s.first][new_s.second]
      = 1 + dist[f_now.first][f_now.second][s_now.first][s_now.second];

    q.push(make_pair(make_pair(new_f, new_f_dir), make_pair(new_s, new_s_dir)));
    runs++;
  }

  cout << ans << "\n";

  return 0;
}
