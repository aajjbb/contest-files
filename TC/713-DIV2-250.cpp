// 2017-05-03T01:37:01+01:00
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

class SymmetryDetection {
public:
    string detect(vector <string>);
};

bool checkV(vector<string> board, int N, int M) {
    vector<string> new_board(N, string(M, '.'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= M / 2; j++) {
            new_board[i][j] = board[i][M - j - 1];
            new_board[i][M - j - 1] = board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        if (new_board[i] != board[i]) {
            return false;
        }
    }
    return true;
}

bool checkH(vector<string> board, int N, int M) {
    vector<string> new_board(N, string(M, '.'));

    for (int j = 0; j < M; j++) {
        for (int i = 0; i <= N / 2; i++) {
            new_board[i][j] = board[N - i - 1][j];
            new_board[N - i - 1][j] = board[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        if (new_board[i] != board[i]) {
            return false;
        }
    }
    return true;
}
string SymmetryDetection::detect(vector <string> board) {
    int N = board.size();
    int M = board[0].size();

    bool isH = checkH(board, N, M);
    bool isV = checkV(board, N, M);

    if (isH && isV) {
        return "Both";
    } else if (!isH && !isV) {
        return "Neither";
    } else if (isH) {
        return "Horizontally symmetric";
    } else {
        return "Vertically symmetric";
    }
}
//Powered by [KawigiEdit] 2.0!
