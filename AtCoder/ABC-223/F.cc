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

struct TreeElement {
    string value;
    bool isBalanced;
};

string A;
TreeElement tree[4 * MAXN];
int lazy[4 * MAXN];

void goDown(int node, int l, int r) {
    if (lazy[node] % 2 == 1) {
        tree[node].value

        if (l != r) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
    }
    lazy[node] = 0;
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = A[l];
    } else {
        int m = (l + r) / 2;

        build(2 * node, l, m);
        build(2 * node + 1, m + 1, r);

        tree[node] = tree[2 * node] && tree[2 * node + 1];
    }
}

bool query(int node, int l, int r, int bl, int br) {
    goDown(node, l, r);
    if (l >= bl && r <= br) {
        return tree[node];
    } else if (l > br || r < bl) {
        return true;
    } else {
        int m = (l + r) / 2;

        Int a = query(2 * node, l, m, bl, br);
        Int b = query(2 * node + 1, m + 1, r, bl, br);

        return a && b;
    }
}

void update(int node, int l, int r, int bl, int br, char value) {
    goDown(node, l, r);
    if (l > r) {
        return;
    } else if (l > br || r < bl) {
        return;
    } else if (l >= bl && r <= br) {
        lazy[node] = value;
        goDown(node, l, r);
    } else {
        int m = (l + r) / 2;

        update(2 * node, l, m, bl, br, value);
        update(2 * node + 1, m + 1, r, bl, br, value);

        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }
}

int main(void) {
    return 0;
}
