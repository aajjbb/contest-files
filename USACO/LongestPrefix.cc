/*
  ID: jeferso1
  PROG: prefix
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

const int MAX_TRIE_SIZE = 80101;
const int MAX_ALPHA = 28;
const int MAX_LEN = 11;

int trie[MAX_TRIE_SIZE][MAX_ALPHA];
bool term[MAX_TRIE_SIZE];
int trie_pointer = 1;

void add_trie(const string& arg) {
  int pos = 0;

  for (char c: arg) {
    int char_pos = c - 'A';
    int next_pos = trie[pos][char_pos];

    if (trie[pos][char_pos] == 0) {
      trie[pos][char_pos] = trie_pointer++;
    }

    pos = trie[pos][char_pos];
  }

  term[pos] = true;
}

int main(void) {
  freopen("prefix.in", "r", stdin);
  freopen("prefix.out", "w", stdout);

  string primitives, sequence;

  while (cin >> primitives && primitives != ".") {
    add_trie(primitives);
  }

  string seq_buffer;

  while (cin >> seq_buffer) {
    sequence += seq_buffer;
  }

  const int n = sequence.size();

  int ans = 0;
  vector<bool> dp(n + 1);

  for (int i = 0; i <= n; i++) {
    int pos = 0;

    for (int j = 0; j < MAX_LEN; j++) {
      if (i + j >= n) {
        break;
      }
      pos = trie[pos][sequence[i + j] - 'A'];

      if (pos == 0) {
        break;
      }

      if (term[pos] && (dp[i] || i == 0)){
        dp[i + j + 1] = true;
      }
    }

    if (dp[i]) {
      ans = i;
    }
  }

  cout << ans << "\n";

  return 0;
}
