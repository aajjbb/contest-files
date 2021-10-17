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
vector<int> G[MAXN];
int vis[MAXN];
int deg[MAXN];
vector<int> order;

int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;

        G[A].push_back(B);

        deg[B] += 1;
    }

    for (int i = 1; i <= N; i++) {
        G[0].push_back(i);
        deg[i] += 1;
    }

    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < N; i++) {
        if(deg[i] == 0) {
            pq.push(i);
        }
    }

    int cnt = 0;

    while (!pq.empty()) {
        int now = pq.top();
        pq.pop();
        order.push_back(now);
        for (int i = 0; i < (int) G[now].size(); i++) {
            int next = G[now][i];
            deg[next] -= 1;

            if(deg[next] == 0) {
                pq.push(next);
            }
        }

        cnt += 1;
    }

    if (cnt != N + 1) {
        cout << "-1\n";
        return 0;
    }

    for (int i = 1; i < order.size(); i++) {
        cout << order[i] << " ";
    }

    cout << endl;


    return 0;
}
