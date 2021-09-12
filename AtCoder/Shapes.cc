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

vector<string> clean(vector<string> input, const int N) {
  vector<string> output;

  int ai = N;
  int bi = 0;
  int aj = N;
  int bj = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (input[i][j] == '.') {
	continue;
      }

      ai = min(ai, i);
      bi = max(bi, i);
      aj = min(aj, j);
      bj = max(bj, j);
    }
  }

  for (int i = ai; i <= bi; i++) {
    string str = "";
    for (int j = aj; j <= bj; j++) {
      str += input[i][j];
    }
    output.push_back(str);

  }

  return output;
}

void print(vector<string> input) {
  for (int i = 0; i < input.size(); i++) {
    for (int j = 0; j < input[i].size(); j++) {
      cout << input[i][j];
    }
    cout << endl;
  }
  cout << endl;
}
vector<string> rotate(vector<string> input) {
  vector<string> rotated;

  const int N = input.size();
  const int M = input[0].size();

  for (int j = 0; j < M; j++) {
    string str = "";
    for (int i = N - 1; i >= 0; i--) {
      str += input[i][j];
    }
    rotated.push_back(str);
  }

  return rotated;
}

int main(void) {
  int N;
  cin >> N;

  vector<string> VA(N), VB(N);

  for (int i = 0; i < N; i++) {
    cin >> VA[i];
  }
  for (int i = 0; i < N; i++) {
    cin >> VB[i];
  }

  VA = clean(VA, N);
  VB = clean(VB, N);

  bool is_possible = false;

  for (int i = 0; i < 4; i++) {
    //print(VA);
    //print(VB);

    if (VA == VB) {
      is_possible = true;
    }
    VB = rotate(VB);
  }

  if (is_possible) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }

  return 0;
}
