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
typedef unsigned uint;

const int MAXN = 1000005;
int tape[MAXN];
int A, B, C, T, command;

int main(void) {
  for ( ; cin >> T && T != 0; ) {
    memset(tape, 0, sizeof(tape));
    printf("MENSAGEM: [");
    bool ok = false;
    for ( ; T > 0; ) {
      cin >> command;
      if (command == 0) {
	ok = true;
      } else if (command == 18) {
	cin >> A >> B >> C;
	A += 1;
	B += 1;
	T -= 3;
	tape[B+1] -= C;
	tape[A] += C;	
      } else if (command == 42) {
	cin >> A;	
	A += 1;
	T -= 1;
	if (!ok) {
	  int df = tape[A];
	  if (df < 0) {
	    printf(" ");
	  } else {
	    printf("%c", ('A' + (df % 26)));
	  }
	}
      }
      T -= 1;
    }
    printf("]\n");
  }
  return 0;
}
