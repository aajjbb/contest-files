#include <cstdlib>
#include <bitset>
#include <functional>
#include <utility>
#include <ctime>
#include <initializer_list>
#include <tuple>
#include <climits>
#include <cfloat>
#include <limits>
#include <exception>
#include <cassert>
#include <cctype>
#include <cstring>
#include <string>
#include <array>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <random>
#include <numeric>
#include <ratio>
#include <cfenv>
#include <iosfwd>
#include <ios>
#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <strstream>
#include <iomanip>
#include <cstdio>

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

int main(void) {
    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        string S;
        cin >> S;

        int cn = 0, cy = 0;
        bool cons = false;

        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 'N') {
                cn += 1;
            } else {
                cy += 1;               
            }
        }

        if (cy >= 2) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}
