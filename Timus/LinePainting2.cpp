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

int N;

void update_answer(int& l, int& r, int new_l, int new_r) {
  if (new_r - new_l + 1 > r - l + 1) {
    l = new_l;
    r = new_r;
  }
}

int main(void) {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;

  // position, (begin or end), color
  set<pair<int, pair<int, char> > > intervals;

  intervals.insert(make_pair(0, make_pair(1, 'w')));
  intervals.insert(make_pair(1000000000, make_pair(2, 'w')));;

  for (int i = 0; i < N; i++) {
    int l, r;
    char color;

    cin >> l >> r >> color;

    intervals.insert(make_pair(l, make_pair(1, color)));
    intervals.insert(make_pair(r, make_pair(2, color)));
  }

  int l = 0;
  int r = 0;
  int local_l = 0;
  bool has_started = false;

  for (auto const& it : intervals) {
    if (it.second.second == 'w') {
      if (!has_started && it.second.first == 1) {
        local_l = it.first;
        has_started = true;
      } else if (has_started && it.second.first == 2) {
        update_answer(l, r, local_l, it.first);
      }
    } else {
      if (has_started && it.second.first == 1) {
        update_answer(l, r, local_l, it.first);
        has_started = false;
      } else if (!has_started && it.second.first == 2) {
        local_l = it.first;
        has_started = true;
      }
    }
  }

  cout << l << " " << r << "\n";

  return 0;
}
