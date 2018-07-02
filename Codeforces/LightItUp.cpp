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

int N, M;

int main(void) {
    cin >> N >> M;

    vector<int> A(N + 2);
	vector<vector<long long> > sum(N + 2, vector<long long>(2, 0));
    
    A[0] = 0;
    A[N + 1] = M;

    long long reg_ans = 0;
    long long ans = 0;
    long long prefA = 0;
    long long prefB = 0;
    
    for (int i = 1; i <= N; i++) {
		cin >> A[i];
    }

	for (int i = N; i >= 0; i--) {
		sum[i][i % 2] += A[i + 1] - A[i];
    }
            
	for (int i = 1; i <= N + 1; i++) {
		if (i % 2 == 1) {
	        reg_ans += A[i] - A[i - 1];

	        ans = max(ans, prefA + (A[i] - A[i - 1] - 1) + sum[i][1]);
            prefA += A[i] - A[i - 1];
        } else {
   	        ans = max(ans, prefB + (A[i] - A[i - 1] - 1) + sum[i][1]);
            prefB += A[i] - A[i - 1];
        }
    }

    cout << max(reg_ans, ans) << endl;
    
    return 0;
}
