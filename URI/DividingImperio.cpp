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

const int MAXN = 100005;

int N;
vector<int> tree[MAXN];
int subtreeSum[MAXN];

void dfs(int node, int parent, int& answer) {
    subtreeSum[node] = 1;

    for (int i = 0; i < (int) tree[node].size(); i++) {
        int next = tree[node][i];

        if (next == parent) {
            continue;
        }

        dfs(next, node, answer);
        subtreeSum[node] += subtreeSum[next];

        int curr_diff = abs(subtreeSum[next] - (N - subtreeSum[next]));
        //cout << curr_diff << endl;
        answer = min(answer, curr_diff);
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    int answer = INT_MAX;

    dfs(1, -1, answer);
    
    cout << answer << "\n";
    return 0;
}
