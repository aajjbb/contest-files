#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <numeric>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>
template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

const int INF = 1000000009;
const int MAX_DP = 100000;
const int MAX_COINS = 5;

int coins[5] = {1, 3, 6, 10, 15};
int dp[MAX_DP];

int func(int v) {
    if (v < 0) {
        return INF;
    } else if (v == 0) {
        return 0;
    } else {
        int& ans = dp[v];

        if (ans == -1) {
            ans = INF;
            
            for (int i = 0; i < MAX_COINS; i++) {
                ans = min(ans, 1 + func(v - coins[i]));
            }
        }

        return ans;
    }
}

int calc(int v) {
    if (v <= MAX_DP - 1) {
        return func(v);
    }
    
    int gap = v - MAX_DP;
    int ans = INF;

    for (int i = MAX_COINS - 1; i >= 0; i--) {
        int used = gap / coins[i];
        int rem = v - used * coins[i];
        
        if (used == 0) {
            ans = min(ans, 1 + calc(rem - coins[i]));
        } else {
            ans = min(ans, used + calc(rem));
        }
    }

    return ans;
}

int main(void) {
    int T;
    cin >> T;

    memset(dp, -1, sizeof(dp));

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        cout << calc(N) << endl;
    }
    return 0;
}
