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
    
int Q;
vector<int> T[MAXN];
int parent[MAXN];
int alive[MAXN];
int alive_subtree[MAXN];
int curr_new_node = 2;
deque<int> nodes;
    
int get_king(int curr_king) {
    if (alive[curr_king]) {
        return curr_king;
    } else {
        for (int i = 0; i < T[curr_king].size(); i++) {
            int next = T[curr_king][i];
    
            if (alive[next]) {
                return next;
            } else if (alive_subtree[next] > 0) {
                return get_king(next);
            }
        }
    
        return parent[curr_king] = get_king(parent[curr_king]);
    }
}
    

void dfs(int node) {
    for (int i = 0; i < T[node].size(); i++) {
        int next_node = T[node][i];

        nodes.push_back(next_node);
        dfs(next_node);
    }
}
int main(void) {
    cin >> Q;

    vector<int> deaths;
    
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;
    
        if (t == 1) {
            T[x].push_back(curr_new_node++);
        } else {
            deaths.push_back(x);
        }
    }

    nodes.push_back(1);
    dfs(1);

    // for (int i = 0; i < nodes.size(); i++) {
    //     cout << nodes[i] << " ";
    // } cout << endl;
    
    memset(alive, 1, sizeof(alive));

    for (int i = 0; i < deaths.size(); i++) {
        alive[deaths[i]] = 0;

        while (!alive[nodes.front()]) {
            nodes.pop_front();
        }
         cout << nodes.front() << "\n";
    }
    
    return 0;
}