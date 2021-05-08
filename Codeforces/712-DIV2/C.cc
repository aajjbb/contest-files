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
const int MAX_OPEN = 17;
const int MAX_CLOSED = 17;
int dp[MAXN][MAX_OPEN][MAX_CLOSED];
string A;
string B;

int func_a(int pos, int open_a, int open_b, int closed_a, int closed_b, const int& N, const string& S) {
    if (closed_a < 0 || closed_b < 0) {
        return 0;
    } else if (pos == N) {
        return closed_a == 0 && closed_b == 0 ? 1 : 0;
    } else {
        int& ans = dp[pos][closed_a][closed_b];

        if (ans == -1) {
            ans = 0;

            if (S[pos] == '1') {
                ans = func_a(pos + 1, 0, 0, closed_a - 1, closed_b - 1, N, S);
                if (ans == 0) {
                    ans = func_a(pos + 1, 1, 1, closed_a + 1, closed_b + 1, N, S);      
                }
            } else {
                ans = func_a(pos + 1, 1, 0, closed_a + 1, closed_b - 1, N, S);
                if (ans == 0) {
                    ans = func_a(pos + 1, 0, 1, closed_a - 1, closed_b + 1, N, S);
                } 
            }
        }

        return ans;
    }
}

int func_b(int pos, int open_a, int open_b, int closed_a, int closed_b, const int& N, const string& S) {
    if (closed_a < 0 || closed_b < 0) {
        return 0;
    } else if (pos == N) {
        return closed_a == 0 && closed_b == 0 ? 1 : 0;
    } else {
        int& ans = dp[pos][closed_a][closed_b];
        //int ans = -1;

        if (ans == -1) {
            ans = 0;

            if (S[pos] == '1') {
                ans = func_b(pos + 1, 1, 1, closed_a + 1, closed_b + 1, N, S);
                if (ans == 0) {
                    ans = func_b(pos + 1, 0, 0, closed_a - 1, closed_b - 1, N, S);
                }
            } else {
                ans = func_b(pos + 1, 0, 1, closed_a - 1, closed_b + 1, N, S);
                if (ans == 0) {
                    ans = func_a(pos + 1, 1, 0, closed_a + 1, closed_b - 1, N, S);
                } 
            }
        }

        return ans;
    }
}



void calc_sa(int pos, int open_a, int open_b, int closed_a, int closed_b, const int& N, const string& S) {
    if (pos == N) {
        return;
    } else {
        if (S[pos] == '1') {
            if (func_a(pos + 1, 0, 0, closed_a - 1, closed_b - 1, N, S)) {
                A += ")";
                B += ")";
                calc_sa(pos + 1, 0, 0, closed_a - 1, closed_b - 1, N, S);                
            } else {
                A += "(";
                B += "(";          
                calc_sa(pos + 1, 1, 1, closed_a + 1, closed_b + 1, N, S);      
            }
        } else {
            if (func_a(pos + 1, 1, 0, closed_a + 1, closed_b - 1, N, S)) {
                A += "(";
                B += ")";
                calc_sa(pos + 1, 1, 0, closed_a + 1, closed_b - 1, N, S);
            } else {
                A += ")";
                B += "(";
                calc_sa(pos + 1, 0, 1, closed_a - 1, closed_b + 1, N, S);
            } 
        }
    }
}

void calc_sb(int pos, int open_a, int open_b, int closed_a, int closed_b, const int& N, const string& S) {
    if (pos == N) {
        return;
    } else {
        if (S[pos] == '1') {
            if (func_b(pos + 1, 1, 1, closed_a + 1, closed_b + 1, N, S)) {
                A += "(";
                B += "(";          
                calc_sb(pos + 1, 1, 1, closed_a + 1, closed_b + 1, N, S);      
            } else {
                A += ")";
                B += ")";
                calc_sb(pos + 1, 0, 0, closed_a - 1, closed_b - 1, N, S);     
            }
        } else {
            if (func_b(pos + 1, 0, 1, closed_a - 1, closed_b + 1, N, S)) {
                A += ")";
                B += "(";                
                calc_sb(pos + 1, 0, 1, closed_a - 1, closed_b + 1, N, S);
            } else {
                A += "(";
                B += ")";
                calc_sb(pos + 1, 1, 0, closed_a + 1, closed_b - 1, N, S);
            } 
        }
    }
}

int main(void) {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        string S;
        cin >> N >> S;

        for (int i = 0; i <= N; i++) {
            for (int j = 0; j < MAX_OPEN; j++) {
                for (int k = 0; k < MAX_CLOSED; k++) {
                    dp[i][j][k] = -1;                
                }
            }
        }

        int is_possible = func_a(0, 0, 0, 0, 0, N, S);

        if (!is_possible) {
            for (int i = 0; i <= N; i++) {
                for (int j = 0; j < MAX_OPEN; j++) {
                    for (int k = 0; k < MAX_CLOSED; k++) {
                        dp[i][j][k] = -1;                
                   }
                }
            }
            int is_possible_b = func_b(0, 0, 0, 0, 0, N, S);

            if (!is_possible_b) {
                cout << "NO\n";
            } else {
                A = "";
                B = "";

                calc_sb(0, 0, 0, 0, 0, N, S);

                cout << "YES\n";
                cout << A << "\n" << B << "\n";
            }
        } else {
            A = "";
            B = "";

            calc_sa(0, 0, 0, 0, 0, N, S);

            cout << "YES\n";
            cout << A << "\n" << B << "\n";
        }
    }
    return 0;
}
