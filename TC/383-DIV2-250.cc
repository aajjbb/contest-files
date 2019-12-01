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

class FloorLayout {
public:
    int countBoards(vector <string>);
};

int FloorLayout::countBoards(vector <string> layout) {
    const int n = (int) layout.size();
    const int m = (int) layout[0].size();
    
    vector<vector<bool>> vis(n, vector<bool>(m));
    
    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (vis[i][j]) {
                continue;
            }
            
            ans += 1;
            
            if (layout[i][j] == '-') {
                for (int k = j; k < m; k++) {
                    if (layout[i][k] != '-') {
                        break;
                    }
                    vis[i][k] = true;
                }
            }
            if (layout[i][j] == '|') {
                for (int k = i; k < n; k++) {
                    if (layout[k][j] != '|') {
                        break;
                    }
                    vis[k][j] = true;
                }
            }
        }
    }
    
    return ans;
}

//Powered by [KawigiEdit] 2.0!
