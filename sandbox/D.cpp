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

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

typedef long long Int;
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 500005;

int N, K;
Int P[MAXN];

vector<double> gauss(vector< vector<double> > A) {
    int n = A.size();

    for (int i=0; i<n; i++) {
        // Search for maximum in this column
        double maxEl = abs(A[i][i]);
        int maxRow = i;
        for (int k=i+1; k<n; k++) {
            if (abs(A[k][i]) > maxEl) {
                maxEl = abs(A[k][i]);
                maxRow = k;
            }
        }

        // Swap maximum row with current row (column by column)
        for (int k=i; k<n+1;k++) {
            double tmp = A[maxRow][k];
            A[maxRow][k] = A[i][k];
            A[i][k] = tmp;
        }

        // Make all rows below this one 0 in current column
        for (int k=i+1; k<n; k++) {
            double c = -A[k][i]/A[i][i];
            for (int j=i; j<n+1; j++) {
                if (i==j) {
                    A[k][j] = 0;
                } else {
                    A[k][j] += c * A[i][j];
                }
            }
        }
    }

    // Solve equation Ax=b for an upper triangular matrix A
    vector<double> x(n);
    for (int i=n-1; i>=0; i--) {
        x[i] = A[i][n]/A[i][i];
        for (int k=i-1;k>=0; k--) {
            A[k][n] -= A[k][i] * x[i];
        }
    }
    return x;
}

int main(void) {
    cin >> N >> K;

    Int all = 0;
    
    for (int i = 0; i < N; i++) {
        cin >> P[i];

        all += P[i];
    }

    Int mean = all / N;
    Int rest = all % N;

    Int steps = 0;
    
    for (int i = 0; i < N; i++) {
        steps += max(0LL, P[i] - mean);
    }

    steps -= rest;

    if (rest == 0 && K >= steps) {
        cout << "0\n";
    } else {    
        if (K >= steps) {
            if (rest > 0) {
                cout << "1\n";
            } else {
                if ((K - steps) % 2 == 0) {
                    cout << "0\n";
                } else {
                    cout << "1\n";
                }
            }
        } else {
            multiset<Int> st;
            for (int i = 0; i < N; i++) {
                st.insert(P[i]);
            }
            for (int x = 0; x < K; x++) {
                multiset<Int>::iterator ia         = st.begin();
                multiset<Int>::reverse_iterator ib = st.rbegin();

                if (abs(*ia - *ib) <= 1) {
                    if ((K - x) % 2 == 1) {
                        cout << 1 - abs(*ia - *ib) << "\n";
                        return 0;
                    } else {
                        cout << abs(*ia - *ib) << "\n";
                        return 0;
                    }
                }

                Int va = *ia;
                Int vb = *ib;
                cout << abs(va - vb) << endl;
                st.erase(ia);
                st.erase(--ib.base());
                st.insert(va + 1);
                st.insert(vb - 1);
            }
            multiset<Int>::iterator ia         = st.begin();
            multiset<Int>::reverse_iterator ib = st.rbegin();
            cout << abs(*ia - *ib) << "\n";
        }
    }
    
    return 0;
}
