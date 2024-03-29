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

int T, N, M;

int main(void) {
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> N >> M;

		for (int i = 0; i < M; i++) {
			cin >> A >> B >> C;
			
			graph[A].push_back(make_pair(B, C));
			graph[B].push_back(make_pair(A, C));
		}
	}
    return 0;
}
