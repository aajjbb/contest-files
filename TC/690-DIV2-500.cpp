// Submitted - 2016-05-31 22:16:54
#include <bits/stdc++.h>

using namespace std;

class GerrymanderEasy {
public:
    double getmax(vector <int>, vector <int>, int);
};

double GerrymanderEasy::getmax(vector <int> A, vector <int> B, int K) {
    double ans = 0.0;
    int N = (int) A.size();


    for (int i = 0; i < N; i++) {
        double X = A[i];
        double Y = B[i];

        for (int j = i + 1; j < N; j++) {
            if (j - i >= K) {
                ans = max(ans, Y / X);
            }
            X += A[j];
            Y += B[j];
        }
        if (N - i >= K) {
            ans = max(ans, Y / X);
        }
    }

    return ans;
}

//Powered by [KawigiEdit] 2.0!
