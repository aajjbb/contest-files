#include <stdio.h>
#include <iostream>
using namespace std;
int T;
string str;

bool func(string& s) {
  int i;
  int ch[256] = {0};

  for (i = 0; i < (int) s.size(); i++) {
    ch[s[i] - 'a'] += 1;
  }

  int cnt = 0;

  for (i = 0; i < 26; i++) {
    if (ch[i] > 0) {
      if (ch[i] % 2 != 0) {
        cnt += 1;
      }
    }
  }

  return cnt <= 1;
}

int main(void) {
  cin >> T;

  int x;
  int i;
  int j;

  for (x = 1; x <= T; x++) {
    cin >> str;

    int N = (int) str.size();

    int ans = 0;

    for (i = 0; i < N; i++) {
      for (j = 1; j <= N - i; j++) {
        string curr = str.substr(i, j);

        //cout << curr << "\n";

        if (func(curr)) {
          ans += 1;
        }
      }
    }

    cout << "Case " << x << ": " << ans << "\n";
  }

  return 0;
}
