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

bool is_valid(const string& S, int N) {
    vector<int> used(N, 0);

    for (int i = 0; i < N; i++) {
        if (S[i] == '1') {
            continue;
        }
        if (S[i] == 'L' && i - 1 >= 0) {
            if (S[i - 1] == '1') {
                used[i - 1] += 1;
            }
        }
        if (S[i] == 'R' && i + 1 < N) {
            if (S[i + 1] == '1') {
                used[i + 1] += 1;
            }
        }
    } 

    for (int i = 0; i < N; i++) {
        if (S[i] == '1' && used[i] == 1) {
            return false;
        }
    } 
    return true;
}

int main(void) {
    int T; 
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        string S;
        cin >> N >> S;

        string S_R = S;
        string S_L = S;

        int cn = 0;

        for (int i = 0; i < N; i++) {
            if (S[i] == '0') {
                if (cn % 2 == 0) {
                    S_R[i] = 'L';
                    S_L[i] = 'R';
                } else {
                    S_R[i] = 'R';
                    S_L[i] = 'L';
                }
                cn += 1;
            }
        }

        // bool valid = true;

        // for (int i = 0; i < N; i++) {
        //     if (S[i] == '1') continue;

        //     if (i - 1 >= 0 && i + 1 < N && S[i - 1] == '1' && S[i + 1] == 1) {
        //         valid = false;
        //     }
        // }

        S = "1" + S + "1";
        if (S.find("11011") == string::npos) {
            cout << "YES\n"; 
        } else {
            cout << "NO\n";
        }

        // if (is_valid(S_L, N)) {
        //     //cout << S_L << "\n";
        //     cout << "YES\n"; 
        // } else if (is_valid(S_R, N)) {
        //     //cout << S_R << "\n";
        //     cout << "YES\n"; 
        // } else {
        //     cout << "NO\n";
        // }
    }

    return 0;
}
