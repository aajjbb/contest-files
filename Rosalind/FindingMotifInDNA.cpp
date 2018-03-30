#include <bits/stdc++.h>

using namespace std;

int T;
string A, B;

vector<int> KMP(string S, string K) {
  vector<int> T(K.size() + 1, -1);
  vector<int> matches;

  if(K.size() == 0) {
    matches.push_back(0);
    return matches;
  }
  for(int i = 1; i <= K.size(); i++) {
    int pos = T[i - 1];
    while(pos != -1 && K[pos] != K[i - 1]) pos = T[pos];
    T[i] = pos + 1;
  }

  int sp = 0;
  int kp = 0;
  while(sp < S.size()) {
    while(kp != -1 && (kp == K.size() || K[kp] != S[sp])) kp = T[kp];
    kp++;
    sp++;
    if(kp == K.size()) matches.push_back(sp - K.size());
  }

  return matches;
}

int main() {
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> A >> B;

    vector<int> ans = KMP(A, B);

    for (int i = 0; i < (int) ans.size(); i++) {
      cout << ans[i] + 1 << " ";
    }
    cout << "\n";
  }
  return 0;
}
