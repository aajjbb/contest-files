#include <iostream>
#include <vector>
#include <algorithm>

#define pb(n) push_back(n)

using namespace std;

struct BootsExchange {
    int leastAmount(vector<int> left, vector<int> right) {
        int i, j, ret = 0, n = left.size();
        vector<bool> usedL(n, false);
        vector<bool> usedR(n, false);

        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(left[i] == right[j] && usedL[i] == false && usedR[j] == false) {
                    usedL[i] = usedR[j] = true;
                    break;
                }
            }
            if(j == n) { ret++; }
        }
        return ret;
    }
};

int main() {
    BootsExchange b;
    vector<int> v1, v2;

    v1.pb(1);
    v1.pb(2);
    v1.pb(3);
    v1.pb(4);
    v1.pb(5);
    v1.pb(6);
    v1.pb(7);

    v2.pb(2);
    v2.pb(4);
    v2.pb(6);
    v2.pb(1);
    v2.pb(3);
    v2.pb(7);
    v2.pb(5);

    cout << b.leastAmount(v1, v2) << endl;
    return 0;
}
