/*
ID: jeferso1
PROG: comehome
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

const int MAXN = 100;

int M;
vector<pair<int, int> > G[MAXN];
int dist[MAXN];

int get_id(char c) {
  if (islower(c)) {
    return c - 'a';
  } else {
    return 27 + (c - 'A');
  }
}

int main(void) {
  freopen("comehome.in", "r", stdin);
  freopen("comehome.out", "w", stdout);

  cin >> M;

  for (int i = 0; i < M; i++) {
    char a, b;
    int c;

    cin >> a >> b >> c;

    G[get_id(a)].push_back(make_pair(get_id(b), c));
    G[get_id(b)].push_back(make_pair(get_id(a), c));
  }

  memset(dist, 63, sizeof(dist));

  priority_queue<pair<int, int> > q;

  q.push(make_pair(0, get_id('Z')));
  dist[get_id('Z')] = 0;

  while (!q.empty()) {
    int ds = -q.top().first;
    int curr = q.top().second;
    q.pop();

    if (curr > 26 && curr != get_id('Z')) {
      cout << char('A' + curr - 27) << " " << ds << "\n";
      break;
    }

    for (int i = 0; i < (int) G[curr].size(); i++) {
      int next = G[curr][i].first;
      int edis = G[curr][i].second;

      if (dist[next] > dist[curr] + edis) {
	dist[next] = dist[curr] + edis;
	q.push(make_pair(-dist[next], next));
      }
    }
  }


  return 0;
}
