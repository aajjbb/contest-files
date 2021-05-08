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

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N, M, X;
        cin >> N >> M >> X;

        vector<pair<int, int> > P(N);
        vector<int> destiny(N);

        for (int i = 0; i < N; i++) {
            cin >> P[i].first;
            P[i].second = i;
        }

        priority_queue<pair<long long, int> > pq;

        for (int i = 0; i < M; i++) {
            pq.push(make_pair(0, i + 1));
        }

        sort(P.rbegin(), P.rend());

        for (int i = 0; i < N; i++) {
            long long smallest = -pq.top().first;
            int block = pq.top().second;
            pq.pop();

            long long new_value = smallest + P[i].first;

            destiny[P[i].second] = block;
            pq.push(make_pair(-new_value, block));
        }

        vector<long long> result(M);

        for (int i = 0; i < M; i++) {
            result[i] = -pq.top().first;
            pq.pop();
        }

        if (llabs(result[0] - result[M - 1]) > X) {
            cout << "NO\n";
        } else {
            cout << "YES\n";

            for (int i = 0; i < N; i++) {
                cout << destiny[i] << " ";
            }
            cout << "\n";
        }
    }
 
    return 0;
}
