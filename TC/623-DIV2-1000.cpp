// Submitted - 2016:07:06 03:48:38
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

class ApplesAndPears {
public:
    int getArea(vector <string>, int);
};

int A[60][60];
int P[60][60];
int E[60][60];

int ApplesAndPears::getArea(vector <string> board, int K) {
    int N = (int) board.size();
    int M = (int) board[0].size();

    int ans = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (board[i][j] == 'A') {
            	A[i][j] += 1;
            } else if  (board[i][j] == 'P') {
            	P[i][j] += 1;
            } else {
            	E[i][j] += 1;
            }

            if (i > 0 && j > 0) {
            	A[i][j] += A[i - 1][j - 1];
            	P[i][j] += P[i - 1][j - 1];
            	E[i][j] += E[i - 1][j - 1];
            }

            for (int k = 0; k < i; k++) {
                A[i][j] += board[k][j] == 'A' ? 1 : 0;
                P[i][j] += board[k][j] == 'P' ? 1 : 0;
                E[i][j] += board[k][j] == '.' ? 1 : 0;
            }
            for (int k = 0; k < j; k++) {
                A[i][j] += board[i][k] == 'A' ? 1 : 0;
                P[i][j] += board[i][k] == 'P' ? 1 : 0;
                E[i][j] += board[i][k] == '.' ? 1 : 0;
            }
        }
    }

    int ap = A[N - 1][M - 1];
    int pe = P[N - 1][M - 1];
    int em = E[N - 1][M - 1];

    //cout << ap << " " << pe << " " << em << endl;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            for (int a = i; a < N; a++) {
                for (int b = j; b < M; b++) {
                    int ee = E[a][b];
                    int aa = A[a][b];
                    int pp = P[a][b];

                    if (i - 1 >= 0 && j - 1 >= 0) {
                    	ee += E[i - 1][j - 1];
                    	aa += A[i - 1][j - 1];
                    	pp += P[i - 1][j - 1];
                    }
                    if (i - 1 >= 0) {
                    	ee -= E[i - 1][b];
                    	aa -= A[i - 1][b];
                    	pp -= P[i - 1][b];
                    }
                    if (j - 1 >= 0) {
                    	ee -= E[a][j - 1];
                    	aa -= A[a][j - 1];
                    	pp -= P[a][j - 1];
                    }

                    if (max(ee, max(pp, aa)) == (a - i + 1) * (b - j + 1)) {
                        //						cout << i << " " << j << " = " << a << " " << b << " => " << aa << " " << pp << " " << ee << endl;
                        ans = max(ans, (a - i + 1) * (b - j + 1));
                    }
                    //Apple
                    if (2 * pp + ee <= K && ap - aa >= ee + pp && em > 0) {
                        ans = max(ans, (a - i + 1) * (b - j + 1));
                    }
                    //Pear
                    if (2 * aa + ee <= K && pe - pp >= ee + aa && em > 0) {
                        ans = max(ans, (a - i + 1) * (b - j + 1));
                    }
                    //Empty
                    if (aa + pp <= K && em - ee >= aa + pp) {
                        ans = max(ans, (a - i + 1) * (b - j + 1));
                    }
                }
            }
        }
    }

    return ans;
}

//Powered by [KawigiEdit] 2.0!
