// 05-25-2024 17:47:22+01:00	Submit	aajjbb	1000	300.00
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
#include <cstring>

using namespace std;


class HillWalker {
public:
  const int INF = 10101010;
  const int MAXN = 27;

  int dx[4] = {0, 0, -1, 1};
  int dy[4] = {-1, 1, 0, 0};

  int getH(char c) {
    if (isupper(c)) {
      return (int) (c - 'A');
    } else {
      return (int) (26 + (c - 'a'));
    }
  }

  int getDist(char a, char b) {
    int ha = getH(a);
    int hb = getH(b);

    if (ha >= hb) {
      return 1;
    } else {
      return (hb - ha) * (hb - ha);
    }
  }

  int highestPoint(vector <string> landscape, int threshold, int timeToDark) {
    int dist[MAXN][MAXN][MAXN][MAXN];

    memset(dist, 63, sizeof(dist));

    int N = landscape.size();
    int M = landscape[0].size();

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	dist[i][j][i][j] = 0;
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	for (int k = 0; k < 4; k++) {
	  int di = i + dx[k];
	  int dj = j + dy[k];

	  if (di < 0 || dj < 0 || di >= N || dj >= M) {
	    continue;
	  }

	  int d = getDist(landscape[i][j], landscape[di][dj]);

	  if (abs(getH(landscape[i][j]) - getH(landscape[di][dj])) > threshold) {
	    continue;
	  }

	  //cout << i << " " << j << " - " << di << " " << dj << " = " << d << endl;

	  dist[i][j][di][dj] = d;
	}
      }
    }

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	for (int a = 0; a < N; a++) {
	  for (int b = 0; b < M; b++) {
	    for (int x = 0; x < N; x++) {
	      for (int y = 0; y < M; y++) {
		dist[a][b][x][y] = min(dist[a][b][x][y], dist[a][b][i][j] + dist[i][j][x][y]);
	      }
	    }
	  }
	}
      }
    }

    int ans = getH(landscape[0][0]);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
	int total = dist[0][0][i][j] + dist[i][j][0][0];

	//cout << i << " " << j << " = " << dist[0][0][i][j] << " + " << dist[i][j][0][0] << " [" << getH(landscape[i][j]) << endl;

	if (total > timeToDark) {
	  continue;
	}

	int ch = getH(landscape[i][j]);

	if (ch > ans) {
	  ans = ch;
	}
      }
    }

    return ans;
  }
};

//Powered by KawigiEdit 2.1.4 (beta) modified by pivanof!
