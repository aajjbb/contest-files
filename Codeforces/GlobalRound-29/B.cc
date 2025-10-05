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
        int N;
        cin >> N;

        vector<int> P(2 * N + 2);

        P[1] = 1;
        int s = N;
        int p = N - 1;

        for (int i = 2; i <= N && s > 1; i++) {
            P[i] = P[i + s] = s;
            s -= 2;
        }

        int last_non_neg = 1;

        while (p > 1) {
            for (int i = last_non_neg; i <= 2 * N; i++) {
                if (P[i] == 0) {
                    int pi = i;

                    while (pi <= 2 * N) {
                        if (P[pi] == 0 && pi != i) {
                            break;
                        }
                        pi += p;
                    }

                    if (pi <= 2 * N && P[pi] == 0) {
                        //cout << p << " " << i << "\n";
                        P[i] = P[pi] = p;
                        p -= 2;
                        last_non_neg = i + 1;
                        break;
                    }
                }
            }
        }

        for (int i = 1; i <= 2 * N; i++) {
            if (P[i] == 0) {
                P[i] = 1;
            }
            cout << P[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
