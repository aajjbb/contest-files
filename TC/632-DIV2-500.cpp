// Submitted - 2014:09:25 18:41:59
#include <bits/stdc++.h>

using namespace std;

class PotentialGeometricSequence {
public:
	int numberOfSubsequences(vector <int>);
};

int PotentialGeometricSequence::numberOfSubsequences(vector <int> d) {
	int N = d.size();
	int ans = N;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			set<int> m;
			m.insert(d[i + 1] - d[i]);

			for (int k = i + 1; k <= j; k++) {
				m.insert(d[k] - d[k - 1]);
			}
			if (m.size() == 1) ans += 1;
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
