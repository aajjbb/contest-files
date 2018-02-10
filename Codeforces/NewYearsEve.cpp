#include <bits/stdc++.h>

using namespace std;

unsigned long long N, K;

int main() {
  cin >> N >> K;

  int msb = 0;

  for (int i = 63; i >= 0; i--) {
    if ((1ULL << i) & N) {
      msb = i;
      break;
    }
  }

  if (K == 1) {
    cout << N << endl;
  } else {
    cout << (1LL << (msb + 1)) - 1 << endl;
  }
  return 0;
}

