
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

const int INF = 1061109567;
const int MAXN = 401;

vector<int> remove_duplicates(const vector<int> v) {
  vector<int> sorted_v = v;

  sort(sorted_v.begin(), sorted_v.end());

  auto uniq = unique(sorted_v.begin(), sorted_v.begin() + sorted_v.size());

  sorted_v.resize(distance(sorted_v.begin(), uniq));

  return sorted_v;
}

int get_position(const vector<int>& v, int value) {
  int l = 0;
  int h = (int) v.size() - 1;

  while (l <= h) {
    int m = (l + h) / 2;

    if (v[m] == value) {
      return m;
    } else if (v[m] < value) {
      l = m + 1;
    } else {
      h = m - 1;
    }
  }

  return -1;
}

int dist_asc[MAXN][MAXN][MAXN];
int dist_des[MAXN][MAXN][MAXN];

int main(void) {
  int N, R, Q;

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> R;

  vector<int> temp(N);

  for (int i = 0; i < N; i++) {
    cin >> temp[i];
  }

  vector<int> unique_temp = temp; //remove_duplicates(temp);
  sort(unique_temp.begin(), unique_temp.end());

  vector<int> sorted_temp = temp;

  int uniq_qt = (int) unique_temp.size();

  sort(sorted_temp.begin(), sorted_temp.end());

  memset(dist_asc, 63, sizeof(dist_asc));
  memset(dist_des, 63, sizeof(dist_des));

  for (int i = 0; i < R; i++) {
    int a, b, c;

    cin >> a >> b >> c;

    for (int j = 0; j < uniq_qt; j++) {
      chmin(dist_asc[a][b][j], c);
      chmin(dist_des[a][b][j], c);

      chmin(dist_asc[b][a][j], c);
      chmin(dist_des[b][a][j], c);
    }
  }

  for (int x = 0; x < uniq_qt; x++) {
    int y = uniq_qt - x - 1;

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        for (int k = 1; k <= N; k++) {
          if (temp[k - 1] <= unique_temp[x]) {
            chmin(dist_asc[i][j][x], dist_asc[i][k][x] + dist_asc[k][j][x]);
          }
          if (temp[k - 1] >= unique_temp[uniq_qt - y - 1]) {
            chmin(dist_des[i][j][y], dist_des[i][k][y] + dist_des[k][j][y]);
          }
        }
      }
    }
  }

  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int a, b, k, t;

    cin >> a >> b >> k >> t;

    int real_pos = k - 1;

    int ans = -1;

    if (t == 0) {
      ans = dist_asc[a][b][real_pos];
    } else {
      ans = dist_des[a][b][real_pos];
    }

    if (ans >= INF) {
      ans = -1;
    }

    cout << ans << endl;
  }

  return 0;
}
