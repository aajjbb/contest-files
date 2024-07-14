// 05-26-2024 21:41:39+01:00	Submit	aajjbb	500	150.00
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


class CollectingRiders {
public:
  const int INF = 10010001;

  int dx[8] = {1, 1, 2, 2, -1, -1, -2, -2};
  int dy[8] = {2, -2, 1, -1, 2, -2, 1, -1};

  vector<vector<int> > calc_dist(vector<string> board, int si, int sj) {
    int n = board.size();
    int m = board[0].size();

    int k = board[si][sj] - '0';

    vector<vector<int>> dist(n, vector<int>(m, INF));

    dist[si][sj] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push(make_pair(0, make_pair(si, sj)));

    while (!pq.empty()) {
      int c_dist = -pq.top().first;
      int ci = pq.top().second.first;
      int cj = pq.top().second.second;

      pq.pop();

      if (c_dist > dist[ci][cj]) {
	continue;
      }

      for (int i = 0; i < 8; i++) {
	int ni = ci + dx[i];
	int nj = cj + dy[i];

	if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
	  continue;
	}

	if (dist[ni][nj] > dist[ci][cj] + 1) {
	  dist[ni][nj] = dist[ci][cj] + 1;
	  pq.push(make_pair(-dist[ni][nj], make_pair(ni, nj)));
	}
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
	if (dist[i][j] >= INF) {
	  continue;
	}
	int c = dist[i][j];

	dist[i][j] = c / k;

	if (c % k != 0) {
	  dist[i][j] += 1;
	}
      }
    }

    return dist;
  }
  int minimalMoves(vector <string> board) {
    vector<vector<vector<int>>> dist_vec;

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
	if (!isdigit(board[i][j])) {
	  continue;
	}
	dist_vec.push_back(calc_dist(board, i, j));
      }
    }

    int ans = INF;

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
	int total_sum = 0;
	for (int k= 0; k < dist_vec.size(); k++) {
	  if (dist_vec[k][i][j] >= INF) {
	    total_sum = INF;
	    break;
	  }
	  total_sum += dist_vec[k][i][j];
	}
	//cout << i << " " << j << " = " << total_sum << endl;
	if (total_sum < ans) {
	  ans = total_sum;
	}
      }
    }

    if (ans >= INF) {
      ans = -1;
    }

    return ans;
  }
};
<%:testing-code%>
   //Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
