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

/**
 * To think of the borders as graph nodes (N, S, E, W), and to
 * connect them with every sensor that touches it. Then, connect
 * every sensor which its area intersect with each other. On the
 * graph build, check whether a border node is connected to a
 * different border node. This means the picture is 'isolated'
 * on its corner. Also, it must be checked whether the initial
 * or picture points are intersected by a sensor area.
 */

int main(void) {
    return 0;
}
