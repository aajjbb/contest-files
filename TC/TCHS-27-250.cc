// 2012-06-12T12:54:44+01:00
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

class BrickMystery {
public:
    vector <string> createPattern(string message)  {
        vector<string> v;
        v.push_back("x.......x");
        for(int i = 0; i < message.size(); i++) {
            string g = "x.......x";
            for(int j = 0; j < 7; j++) {
                int n = (int) message[i];
                if((n & 1 << j)) {
                    g[j + 1] = 'x';
                }
            }
            reverse(g.begin(), g.end());
            v.push_back(g);
        }
        v.push_back("x.......x");
        return v;
    }
};

// Powered by FileEdit
