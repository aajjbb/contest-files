#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class SwapTheString {
public:
	long long findNumberOfSwaps(string, int, int, int, int, int);
};

long long SwapTheString::findNumberOfSwaps(string P, int A0, int X, int Y, int N, int K) {
	const long long MOD = 1812447359LL;
	long long ans = 0LL;
	
	vector<long long> A(N);
	A[0] = A0;
	
	for (int i = 1; i < N; i++) {
		A[i] = (A[i - 1] * (long long) X + Y) % MOD;
		A[i] %= MOD;
	}
	
	string S(N, ' ');
	
	for (int i = 0; i < P.size(); i++) {
		S[i] = P[i];
	}
	for (int i = P.size(); i < N; i++) {
		S[i] = (char) ((A[i] % 26) + 'a');
	}
	
	for (int k = 0; k < K; k++) {
		vector<int> sum(26, 0);
		
		for (int i = k; i < N; i += K) {
			int pos = S[i] - 'a';
			sum[pos] += 1;
			for (int j = 0; j < pos; j++) {
				ans += sum[j];
			}
		}
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!
