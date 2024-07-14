// 11-28-2019 00:20:38+01:00	Submit	aajjbb	500	150.00
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Planks {
public:
    int makeSimilar(vector <int>, int, int);
};

int calculate(const vector<int> lengths, const int costPerCut, const int woodValue, const int goalSize) {
    int ans = 0;

    for (int i = 0; i < (int) lengths.size(); i++) {
        int pieces = lengths[i] / goalSize;
        int cuts = pieces;

        if (lengths[i] % goalSize == 0) {
            cuts -= 1;
        }

        ans += max(0, pieces * goalSize * woodValue - cuts * costPerCut);
    }

    return ans;
}

int Planks::makeSimilar(vector <int> lengths, int costPerCut, int woodValue) {
    int ans = 0;

    for (int i = 1; i <= 10000; i++) {
        int value = calculate(lengths, costPerCut, woodValue, i);

        ans = max(ans, value);
    }

    return ans;
}

//Powered by [KawigiEdit] 2.0!
