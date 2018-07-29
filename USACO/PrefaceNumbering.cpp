/*
ID: jeferso1
LANG: C++
TASK: preface
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

const string ROMAN_CHARS = "IVXLCDM";
// (digit, power) => romam
string mapping[10][4];

void buildMapping() {
  mapping[1][0] = "I";
  mapping[2][0] = "II";
  mapping[3][0] = "III";
  mapping[4][0] = "IV";
  mapping[5][0] = "V";
  mapping[6][0] = "VI";
  mapping[7][0] = "VII";
  mapping[8][0] = "VIII";
  mapping[9][0] = "IX";

  mapping[1][1] = "X";
  mapping[2][1] = "XX";
  mapping[3][1] = "XXX";
  mapping[4][1] = "XL";
  mapping[5][1] = "L";
  mapping[6][1] = "LX";
  mapping[7][1] = "LXX";
  mapping[8][1] = "LXXX";
  mapping[9][1] = "XC";

  mapping[1][2] = "C";
  mapping[2][2] = "CC";
  mapping[3][2] = "CCC";
  mapping[4][2] = "CD";
  mapping[5][2] = "D";
  mapping[6][2] = "DC";
  mapping[7][2] = "DCC";
  mapping[8][2] = "DCCC";
  mapping[9][2] = "CM";

  mapping[1][3] = "M";
  mapping[2][3] = "MM";
  mapping[3][3] = "MMM";
}

string to_roman(int arg) {
  assert(arg > 0);

  string ans = "";
  vector<int> digits;

  while (arg > 0) {
    digits.push_back(arg % 10);
    arg /= 10;
  }

  // reverse to get most -> least significant order
  reverse(digits.begin(), digits.end());

  for (int i = 0; i < digits.size(); i++) {
    ans += mapping[digits[i]][digits.size() - i - 1];
  }

  return ans;
}

int main(void) {
  freopen("preface.in", "r", stdin);
  freopen("preface.out", "w", stdout);

  int N;
  map<char, int> char_cnt;

  cin >> N;

  buildMapping();

  for (int i = 1; i <= N; i++) {
    string roman = to_roman(i);

    for (int j = 0; j < (int) roman.size(); j++) {
      char_cnt[roman[j]] += 1;
    }
  }

  for (char value: ROMAN_CHARS) {
    if (char_cnt[value] > 0) {
      cout << value << " " << char_cnt[value] << "\n";
    }
  }

  return 0;
}
