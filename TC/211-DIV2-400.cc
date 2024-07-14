// 05-26-2024 22:32:25+01:00	Submit	aajjbb	400	395.83
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
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


class grafixCorrupt {
public:
  int selectWord(vector <string> dictionary, string candidate) {
    int ans = -1;
    int curr_match = 0;

    for (int i = 0; i < dictionary.size(); i++) {
      int m = 0;
      for (int j = 0; j < candidate.size(); j++) {
	if (candidate[j] == dictionary[i][j]) {
	  m += 1;
	}
      }
      if (curr_match < m) {
	curr_match = m;
	ans = i;
      }
    }

    return ans;
  }
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
