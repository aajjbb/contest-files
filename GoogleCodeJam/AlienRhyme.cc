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

int T, N;

int main(void) {
    cin >> T;

    for (int t = 1; t <= T; t++) {
		cin >> N;

        vector<string> S(N);
        vector<int> pos(N);
        vector<vector<int> > groups;
        vector<int> dummy;

        for (int i = 0; i < N; i++) {
			cin >> S[i];
            pos[i] = S[i].size() - 1;
            dummy.push_back(i);
        }

        groups.push_back(dummy);

        int ans = 0;

        while (!groups.empty()) {
            cout << groups.size() << endl;
            vector<vector<int> > new_groups;

			for (int i = 0; i < (int) groups.size(); i++) {
                if (groups[i].size() <= 1) {
					continue;
                } else if (groups[i].size() == 2 || groups[i].size() == 3) {
					ans += 2;
                    continue;
                }
				vector<int> splitted[27];

                for (int j = 0; j < (int) groups[i].size(); j++) {
                    int s_id = groups[i][j];
                    int string_pos = pos[s_id];

                    if (string_pos < 0) {
                        splitted[26].push_back(s_id);
                    } else {
                        pos[s_id] -= 1;

	                    int cr = S[s_id][string_pos] - 'A';

						splitted[cr].push_back(s_id);
                    }
                }

				if (splitted[26].size() >= 2) {
					ans += 2;
				}

				for (int j = 0; j < 26; j++) {
					if (splitted[j].size() == 2 || splitted[j].size() == 3) {
						ans += 2 ;
                    } else {
						if (splitted[j].size() > 3) {
							new_groups.push_back(splitted[j]);
						}
                    }
				}
            }

            groups = new_groups;
        }

        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}
