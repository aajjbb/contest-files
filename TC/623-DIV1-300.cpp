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
typedef unsigned uint;

class UniformBoard {
public:
    int getBoard(vector <string>, int);
};

int UniformBoard::getBoard(vector <string> board, int K) {
    int N = (int) board.size();
    int M = (int) board[0].size();

    int ans = 0;
    int all = 0;
    bool has_empty = false;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'A') {
                all += 1;
            }
            if (board[i][j] == '.') {
                has_empty = true;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int a = i; a < N; a++) {
                for (int b = j; b < M; b++) {
                    int ee = 0;
                    int aa = 0;
                    int pp = 0;

                    for (int p = i; p <= a; p++) {
                        for (int q = j; q <= b; q++) {
                            if (board[p][q] == '.') ee += 1;
                            else if (board[p][q] == 'A') aa += 1;
                            else if (board[p][q] == 'P') pp += 1;
                        }
                    }

                    if (ee + pp > 0 && !has_empty) continue;

                    if (K >= 2 * pp + ee && all - aa >= pp + ee) {
                        //						cout << i << " " << j << " " <<  a<< " " << b << endl;
                        ans = max(ans, (a - i + 1) * (b - j + 1));
                    }
                }
            }
        }
    }
    return ans;
}

//Powered by [KawigiEdit] 2.0!
