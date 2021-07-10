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

const long long INF = 10000000000000000LL;

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, K;
        cin >> N >> K;

        vector<long long> P(K), Q(K);
        vector<long long> cost(N + 1, INF);

        vector<pair<long long, long long> > PQ(K);

        for (int i = 0; i < K; i++) {
            cin >> P[i];
        }
        for (int i = 0; i < K; i++) {
            cin >> Q[i];

            PQ[i].first = P[i];
            PQ[i].second = Q[i];
        }


        sort(PQ.begin(), PQ.end(), [](const pair<long long, long long> pa, const pair<long long, long long> pb) {
            return pa.second > pb.second;
        });

        for (int i = 0; i < K; i++) {
            int l = 1;
            int h = PQ[i].first;

            int limit_l = 1;
            int limit_r = N;

            while (l <= h) {
                int m = (l + h) / 2;
                long long new_cost = PQ[i].second + llabs(m - PQ[i].first);

                if (new_cost <= cost[m]) {
                    limit_l = m;
                    h = m - 1;
                } else {
                    l = m + 1;
                }
            }

            l = PQ[i].first;
            h = N;

            while (l <= h) {
                int m = (l + h) / 2;
                long long new_cost = PQ[i].second + llabs(m - PQ[i].first);

                if (new_cost <= cost[m]) {
                    limit_r = m;
                    l = m + 1;
                } else {
                    h = m - 1;                    
                }
            }

            for (int j = limit_l; j <= limit_r; j++) {
                cost[j] = min(cost[j], PQ[i].second + llabs(j - PQ[i].first)); 
            }
        }

        for (int i = 1; i <= N; i++) {
            cout << cost[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
