// Submitted - 2016-03-29 04:44:11
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
typedef unsigned uint;

class SegmentsAndPoints {
public:
    string isPossible(vector <int>, vector <int>, vector <int>);
};

const int MAXN = 210;
int N;
vector<int> graph[MAXN];
int matchR[MAXN], vis[MAXN];

bool bpm(int u, bool seen[], int matchR[]) {
    for (int i = 0; i < (int) graph[u].size(); i++) {
        int v = graph[u][i];

        if (!seen[v]) {
            seen[v] = true;

            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR)) {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

int maxBPM() {
    int matchR[MAXN];

    memset(matchR, -1, sizeof(matchR));

    int result = 0;
    for (int u = 0; u < N; u++) {
        bool seen[MAXN];
        memset(seen, 0, sizeof(seen));

        if (bpm(u, seen, matchR)) {
            result++;
        }
    }
    return result;
}

string SegmentsAndPoints::isPossible(vector <int> p, vector <int> l, vector <int> r) {
    N = (int) p.size();

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (p[i] >= l[j] && p[i] <= r[j]) {
                graph[i].push_back(N + j);
            }
        }
    }

    return maxBPM() == N ? "Possible" : "Impossible";
}

//Powered by [KawigiEdit] 2.0!
