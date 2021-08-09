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
#include <cstring>

using namespace std;

class IOISureWinner {
public:
	double probability(int, vector <int>, vector <int>);
};

double dp[60][400];

double func(int pos, int scoreSum, const int scoreNeeded, const vector<int> subtasks, const vector<int> p) {
  if (pos >= subtasks.size()) {
    return scoreSum >= scoreNeeded ? 1.0 : 0.0;
  } else {
    double& ans = dp[pos][scoreSum];

    if (ans > -1 + 1e-7) {
      return ans;
    }

    ans = 0.0;

    ans += (p[pos] / 100.0) * func(pos + 1, scoreSum + subtasks[pos], scoreNeeded, subtasks, p);
    ans += (1 - p[pos] / 100.0) * func(pos + 1, scoreSum, scoreNeeded, subtasks, p);

    return ans;
  }
}

double IOISureWinner::probability(int scoreNeeded, vector <int> subtasks, vector <int> p) {
  memset(dp, -1, sizeof(dp));
  double prob = func(0, 0, scoreNeeded, subtasks, p);

  return prob;
}

//Powered by [KawigiEdit] 2.0!
