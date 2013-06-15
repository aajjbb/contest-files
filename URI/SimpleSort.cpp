#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

int i, a[3], b[3];

int main(void) {
    scanf("%d%d%d", &a[0], &a[1], &a[2]);
    b[0] = a[0]; b[1] = a[1]; b[2] = a[2];
    sort(a, a + 3);
    REP(i, 3) {
        printf("%d\n", a[i]);
    }
    printf("\n");
    REP(i, 3) {
        printf("%d\n", b[i]);
    }
    return 0;
}


