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

const int MAXN = 200005;

int N, M;
vector<int> g[MAXN];
int out[MAXN];
int vis[MAXN];

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        g[b].push_back(a);
        out[a] += 1;
    }


    int ans = N;
    queue<int> q;

    for (int i = 1; i <= N; i++) {
        if(out[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        vis[curr] = true;

        ans -= 1;

        for (int i = 0; i < g[curr].size(); i++) {
            int next = g[curr][i];

            out[next] -= 1;

            if (out[next] == 0 && !vis[next]) {
                vis[next] = true;
                q.push(next);
            }
        }
    }

    cout << ans << "\n";

    return 0;
}