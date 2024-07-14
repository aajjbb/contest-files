// 2024-05-26T21:58:16+01:00
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

class FieldPairParse {
public:
  vector <int> getPairs(vector <string> data) {
    string summary = "";

    int n = data.size();
    int m = data[0].size();


    for (int j = 0; j < m; j++) {
      bool all_space = true;

      for (int i = 0; i < n; i++) {
	if (data[i][j] != ' ') {
	  all_space = false;
	  break;
	}
      }

      if (all_space) {
	summary += "-";
      } else {
	summary += "X";
      }
    }

    vector<int> ans;

    cout << summary << "\n";

    for (int i = 0; i < m; i++) {
      if (summary[i] != '-') {
	continue;
      }
      int j = i;

      while (j < m && summary[j] == '-') {
	j += 1;
      }

      ans.push_back(j - i);
      i = j - 1;
    }

    if (ans.size() % 2 == 0) {
      return vector<int>();
    }

    return ans;
  }
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
