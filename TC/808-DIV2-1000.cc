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
#include <climits>
#include <queue>

using namespace std;

class IOIVoting {
public:
  vector <int> winners(int, vector <int>);
};

const int INF = INT_MAX / 5;

vector <int> IOIVoting::winners(int N, vector <int> votes) {
  vector<vector<int> > G(N, vector<int>());
  vector<vector<int> > arg(N, vector<int>(N, 0));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (votes[i*N+j] > votes[j*N+i]) {
	//cout << i << " " << j << endl;
	G[i].push_back(j);
      }
    }
  }

  for (int i = 0; i < N; i++) {
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(INF, i));

    while (!pq.empty()) {
      int arg_st = pq.top().first;
      int arg_end = pq.top().second;
      pq.pop();

      arg[i][arg_end] = max(arg[i][arg_end], arg_st);

      //cout << i << " " << arg_prv << " " << arg_end << " " << arg_st << endl;

      for (int j = 0; j < G[arg_end].size(); j++) {
	int next_id = G[arg_end][j];
	int next_arg = min(arg_st, votes[arg_end*N+next_id] - votes[next_id*N+arg_end]);

	//cout << i << " " << arg_end << " " << next_id << " = " << next_arg << endl;

	if (arg[i][next_id] < next_arg) {
	  arg[i][next_id] = next_arg;
	  pq.push(make_pair(next_arg, next_id));
	}
      }
    }
  }

  vector<int> ans;

  for (int i = 0; i < N; i++) {
    bool big = true;

    for (int j = 0; j < N; j++) {
      if (i == j) continue;

      //cout << i << " " << j << " " << arg[i][j] << endl;

      if (arg[i][j] < arg[j][i]) {
	big = false;
      }
    }
    //cout << endl;
    if (big) {
      ans.push_back(i);
    }
  }

  return ans;
}

//Powered by [KawigiEdit] 2.0!
