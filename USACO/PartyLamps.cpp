/*
  ID: jeferso1
  LANG: C++
  TASK: lamps
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

int N, C;

bool cmp(const string& a, const string& b) {
  assert(a.size() == b.size());

  for (int i = 0; i < a.size(); i++) {
    if (a[i] != b[i]) {
      return a[i] < b[i];
    }
  }

  return true;
}

vector<int> button1(vector<int> state) {
  for (int i = 0; i < state.size(); i++) {
    state[i] ^= 1;
  }

  return state;
}

vector<int> button2(vector<int> state) {
  for (int i = 0; i < state.size(); i++) {
    // even as implementation is 0-based
    if (i % 2 == 0) {
      state[i] ^= 1;
    }
  }

  return state;
}

vector<int> button3(vector<int> state) {
  for (int i = 0; i < state.size(); i++) {
    // even as implementation is 0-based
    if (i % 2 == 1) {
      state[i] ^= 1;
    }
  }

  return state;
}

vector<int> button4(vector<int> state) {
  for (int i = 0; i < state.size(); i++) {
    int pos = 3 * i;
    if (pos >= state.size()) {
      break;
    }
    state[pos] ^= 1;
  }

  return state;
}

int main(void) {
  freopen("lamps.in", "r", stdin);
  freopen("lamps.out", "w", stdout);

  cin >> N >> C;

  int buff_int = 0;
  vector<int> on_lamp, off_lamp;
  vector<string> ans_vec;

  while (cin >> buff_int && buff_int != -1) {
    on_lamp.push_back(buff_int - 1);
  }

  while (cin >> buff_int && buff_int != -1) {
    off_lamp.push_back(buff_int - 1);
  }

  for (int i = 0; i < (1 << 4); i++) {
    int moves = __builtin_popcount(i);

    if (moves > C || (C - moves) % 2 != 0) {
      continue;
    }

    vector<int> state(N, 1);

    if (i & 1) {
      state = button1(state);
    }
    if (i & 2) {
      state = button2(state);
    }
    if (i & 4) {
      state = button3(state);
    }
    if (i & 8) {
      state = button4(state);
    }

    bool fine = true;

    for (int j = 0; j < on_lamp.size(); j++) {
      if (state[on_lamp[j]] == 0) {
        fine = false;
      }
    }
    for (int j = 0; j < off_lamp.size(); j++) {
      if (state[off_lamp[j]] == 1) {
        fine = false;
      }
    }

    if (fine) {
      string as_string = "";

      for (int j = 0; j < N; j++) {
        if (state[j] == 1) {
          as_string += "1";
        } else {
          as_string += "0";
        }
      }

      ans_vec.push_back(as_string);
    }
  }

  if (ans_vec.empty()) {
    cout << "IMPOSSIBLE\n";
  } else {
    sort(ans_vec.begin(), ans_vec.end(), cmp);

    for (int i = 0; i < ans_vec.size(); i++) {
      cout << ans_vec[i] << "\n";
    }
  }
  return 0;
}
