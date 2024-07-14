//10-09-2014 00:28:07+01:00	Submit	aajjbb	1050	737.97
#include <bits/stdc++.h>

using namespace std;

class JimmyLightning {
public:
	int robTheBank(vector <int>, vector <string>);
};

int N, M;
int dp[55][55][1010];
vector<pair<int, int> > D[55];
int shut_time[55];

int func(int id, int us_id, int t) {
	if (id == N) {
		return 0;
	} else {
		int& ans = dp[id][us_id][t];

		if (ans == -1) {
			ans = 0;

			ans = func(id + 1, 0, t);

			for (int i = 0; i < (int) D[id].size(); i++) {
				int n_id = id;
				int n_us_id = i + 1;

				if (n_us_id >= D[id].size()) {
					n_id += 1;
					n_us_id = 0;
				}

				for (int j = 1; t + D[id][i].second * j < shut_time[id]; j++) {
					ans = max(ans, D[id][i].first * j + func(n_id, n_us_id, t + D[id][i].second * j));
				}
			}
		}

		return ans;
	}
}

int JimmyLightning::robTheBank(vector <int> doors, vector <string> diamonds) {
	N = (int) doors.size();
	M = (int) diamonds.size();

	for (int i = 0; i < M; i++) {
		int v, t, r;
		sscanf(diamonds[i].c_str(), "%d%d%d", &v, &t, &r);
		D[N-r].push_back(make_pair(v, t));
	}

	reverse(doors.begin(), doors.end());

	for (int i = 0; i < N; i++) {
		shut_time[i] = doors[i];

		for (int j = i + 1; j < N; j++) {
			shut_time[i] = min(shut_time[i], doors[j]);
		}
	}

	memset(dp, -1, sizeof(dp));

	int ans = func(0, 0, 0);

	return ans;
}

//Powered by [KawigiEdit] 2.0!
