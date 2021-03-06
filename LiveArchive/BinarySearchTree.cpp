#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int N;
int P[MAXN];
vector<int> tree[MAXN];
int used[MAXN];
int id = 1;

void add(int node, int value, int prev, int from) {  
    //cout << node << "\n";
    if (node == -1) {
        node = id++;
    
        used[node] = value;
        if (prev != -1) {
            tree[prev][from] = node;
        }
    } else {
        if (value < used[node]) {
            add(tree[node][0], value, node, 0);
        } else {
            add(tree[node][1], value, node, 1);
        }
    }
}

void post(int node) {
    if (node == -1) {
        return;
    }
    if (tree[node].size() > 0) {
        post(tree[node][0]);
    }
    if (tree[node].size() > 1) {
        post(tree[node][1]);
    }
    if (used[node] != -1) {
        cout << used[node] << "\n";
    }
}

int main() {
    memset(used, -1, sizeof(used));

    while (1) {
        int b;
        if (!(cin >> b)) {
            break;
        }
        tree[N].push_back(-1);
        tree[N].push_back(-1);
        P[N++] = b;
    }

    for (int i = 0; i < N; i++) {
        add(0, P[i], -1, -1);
    }

    post(0);
  
    return 0;
}
