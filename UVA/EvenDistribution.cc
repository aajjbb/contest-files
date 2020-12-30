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

const int MAXN = 10005;

vector<int> graph[MAXN];
int C[MAXN];
set<int> div_pd[MAXN];
set<int> seen_gcd[MAXN];

set<int> get_divisors(int arg) {
    if (!div_pd[arg].empty()) {
        return div_pd[arg];
    }

    set<int> ans;

    for (int i = 1; i <= (int) sqrt(arg); i++) {
        if (arg % i != 0) {
            continue;
        }

        ans.insert(i);
        ans.insert(arg / i);
    }

    return div_pd[arg] = ans;
}

int main(void) {
    int N, M;

    while (cin >> N >> M) {
        set<int> valid_k;

        for (int i = 1; i <= N; i++) {
            cin >> C[i];

            // Clear previous input.
            graph[i].clear();
            seen_gcd[i].clear();
        }

        for (int i = 0; i < M; i++) {
            int a, b;
            cin >> a >> b;

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<pair<int, int>> q;

        for (int i = 1; i <= N; i++) {
            q.push(make_pair(i, C[i]));
            seen_gcd[i].emplace(C[i]);
            valid_k.insert(C[i]);
        }

        while (!q.empty()) {
            auto q_front = q.front();
            q.pop();

            int node = q_front.first;
            int path_gcd = q_front.second;

            for (int i = 0; i < graph[node].size(); i++) {
                int next_node = graph[node][i];
                int next_path_gcd = gcd(path_gcd, C[next_node]);

                if (seen_gcd[next_node].count(next_path_gcd)) {
                    continue;
                }

                seen_gcd[next_node].emplace(next_path_gcd);
                valid_k.insert(next_path_gcd);
                q.push(make_pair(next_node, next_path_gcd));
            }
        }

        cout << valid_k.size() << "\n";
    }
    return 0;
}
