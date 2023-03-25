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

const int MAXN = 22;
int R, C;
vector<string> grid, new_grid;

int main(void) {
    cin >> R >> C;

    grid.resize(R);
    new_grid.resize(R);

    for (int i = 0; i < R; i++) {
        cin >> grid[i];
        new_grid[i] = grid[i];
        //cerr << grid[i] << "\n";
    }

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (!(grid[i][j] >= '1' && grid[i][j] <= '9')) {
                continue;
            }
            int len = grid[i][j] - '0';

            for (int a = 0; a < R; a++) {
                for (int b = 0; b < C; b++) {
                    if (abs(i - a) + abs(j - b) > len) {
                        continue;
                    }
                    new_grid[a][b] = '.';
                }
            }
        }
    }

    for (int i = 0; i < R; i++) {
        cout << new_grid[i] << "\n";
    }
    return 0;
}
