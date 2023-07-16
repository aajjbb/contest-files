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

const int MAXN = 2001;

int N, M;

vector<vector<int> > multiply(vector<vector<int> > a, vector<vector<int> > b) {
	vector<vector<int> > res(a.size(), vector<int>(a[0].size()));
	for(int i = 0; i < a.size(); i++) {
		for(int j = 0; j < a[0].size(); j++) {
			int sum = 0;
			for (int k = 0; k < a.size(); k++) {
				sum += a[i][k] * b[k][j];
			}
			res[i][j] = sum;
		}
	}
	return res;
}

vector<vector<int> > binPow(vector<vector<int> > a, int n) {
	if (n == 1) {
		return a;
	} else if ((n & 1) != 0) {
		return multiply(a, binPow(a, n - 1));
	} else {
		vector<vector<int> > b = binPow(a, n / 2);
		return multiply(b, b);
	}
}

int main(void) {
    cin >> N >> M;

    vector<vector<int>> mat(N + 1, vector<int>(N + 1));

    for (int i = 0; i < M; i++) {
        int a, b;

        cin >> a >> b;

        mat[a][b] = 1;
    }

    if (M == 0) {
        cout << 0 << endl;
        return 0;
    }

    int ans = 0;

    while (true) {
        bool finished = true;

        vector<vector<int>> ret = binPow(mat, 2);

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                //cout << i << " " << j << " " << mat[i][j] << " - " << ret[i][j] << endl;
                if (ret[i][j] > 0 && mat[i][j] == 0) {
                    mat[i][j] = 1;
                    ans += 1;
                    finished = false;
                    //goto end;
                }
            }
        }
        //end:;
        //cout << endl;
        if (finished) {
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}
