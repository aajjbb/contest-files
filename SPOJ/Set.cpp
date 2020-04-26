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

int get_num_bit(string arg) {
  if (arg == "um") {
    return 0;
  } else if (arg == "dois") {
    return 1;
  } else {
    return 2;
  }
}

int get_kind_bit(string arg) {
  if (arg == "circulo" || arg == "circulos") {
    return 3;
  } else if (arg == "triangulo" || arg == "triangulos") {
    return 4;
  } else {
    return 5;
  }
}

int main(void) {
  int N;

  vector<int> possibility;

  for (int i = 0; i <= 2; i++) {
    for (int j = 3; j <= 5; j++) {
      possibility.push_back((1 << i) | (1 << j));
    }
  }

  vector<tuple<int, int, int> > valid_set;
  int poss_len = (int) possibility.size();

  for (int i = 0; i < poss_len; i++) {
    valid_set.push_back(make_tuple(possibility[i], possibility[i], possibility[i]));

    for (int j = i + 1; j < poss_len; j++) {
      for (int k = j + 1; k < poss_len; k++) {
	int comb = possibility[i] | possibility[j] | possibility[k];

	// checking how many bit sets on [0..2], [3..5]
	int fst = ((1 << 0) | (1 << 1) | (1 << 2)) & comb;
	int snd = ((1 << 3) | (1 << 4) | (1 << 5)) & comb;

	if (__builtin_popcount(fst) == 2 || __builtin_popcount(snd) == 2) {
	  continue;
	}
	valid_set.push_back(make_tuple(possibility[i], possibility[j], possibility[k]));
      }
    }
  }

  while (cin >> N) {
    if (N == 0) {
      break;
    }

    vector<int> cnt(40, 0);

    for (int i = 0; i < N; i++) {
      string num, kind;
      cin >> num >> kind;

      int num_bit = get_num_bit(num);
      int kind_bit = get_kind_bit(kind);

      int id = (1 << num_bit) | (1 << kind_bit);

      cnt[id] += 1;
    }

    int ans = 0;

    for (int t = 0; t < 100; t++) {
      int local_ans = 0;
      vector<int> cnt_cpy = cnt;

      random_shuffle(valid_set.begin(), valid_set.end());

      for (int i = 0; i < valid_set.size(); i++) {
	int a = get<0>(valid_set[i]);
	int b = get<1>(valid_set[i]);
	int c = get<2>(valid_set[i]);

	int value = min(cnt_cpy[a], min(cnt_cpy[b], cnt_cpy[c]));

	if (a == b && a == c) {
	  value = cnt_cpy[a] / 3;
	}

	if (value == 0) {
	  continue;
	}

	local_ans += value;

	if (a == b && a == c) {
	  cnt_cpy[a] %= 3;
	} else {
	  cnt_cpy[a] -= value;
	  cnt_cpy[b] -= value;
	  cnt_cpy[c] -= value;
	}
      }

      ans = max(ans, local_ans);
    }

    cout << ans << "\n";
  }
  return 0;
}
