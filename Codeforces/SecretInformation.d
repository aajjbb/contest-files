import std.stdio, std.string, std.conv;
import std.algorithm, std.array, std.bigint, std.math, std.range;
import core.thread;

//	Input
string[] tokens;
int tokenId = 0;
string readToken() { for (; tokenId == tokens.length; ) tokens = readln.split, tokenId = 0; return tokens[tokenId++]; }

int readInt() { return to!int(readToken); }
long readLong() { return to!long(readToken); }
real readReal() { return to!real(readToken); }

//	chmin/chmax
void chmin(T)(ref T t, T f) { if (t > f) t = f; }
void chmax(T)(ref T t, T f) { if (t < f) t = f; }

int N;
string A, B;

void main () {
  N = readInt();
  A = readToken();
  B = readToken();

  int i;
  int j;
  int ans = 0;

  for (i = 0; i < N; i++) {
    j = i;
    
    while (j < N && A[j] != B[j]) j += 1;

    if (i != j) {
      ans += 1;
    }
    i = j;
  }

  writeln(ans);  
}
