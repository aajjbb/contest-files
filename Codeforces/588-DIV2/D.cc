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

const int MAXN = 7001;

int N;
long long A[MAXN];
int B[MAXN];
bool vis[MAXN];
vector<int> G[MAXN];
queue<int> q;

int main(void) {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    long long ans = 0;
    unordered_set<int> has_equal;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            if (A[i] == A[j]) {
                has_equal.insert(i);
            }
            if ((A[i] & A[j]) == A[i]) {
                G[j].push_back(i);
            }
        }
    }
    for (auto elem : has_equal) {
        if (vis[elem]) {
            continue;
        }

        q.push(elem);
        vis[elem] = true;

        while (!q.empty()) {
            int curr_node = q.front();
            q.pop();

            ans += B[curr_node];

            for (int i = 0; i < G[curr_node].size(); i++) {
                int next = G[curr_node][i];

                if (!vis[next]) {
                    q.push(next);
                    vis[next] = true;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
