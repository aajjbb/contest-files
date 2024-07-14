// 2012-01-09T21:44:28+01:00
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <memory>
#include <iomanip>
#include <functional>
#include <new>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cctype>
#include <ctime>

#define REP(i, n) for((i) = 0; i < n; i++)
#define FOR(i, a, n) for((i) = a; i < n; i++)
#define FORR(i, a, n) for((i) = a; i <= n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long int64;

struct FireSimulation {
	vector <string> getState(vector <string> field, int minute) {
		int i, j, N = sz(field), M = sz(field[0]);

		int state[N][M], values[N][M];

		REP(i, N) { REP(j, M) { state[i][j] = field[i][j] - '0'; values[i][j] = 0; } }

		field[0][0] = '*';

		for(int x = 0; x != minute + 1; x++) {
			for(int i = 0; i < N; i++) {
				for(int j = 0; j < M; j++) {
					if(values[i][j] >= state[i][j] && field[i][j] == '*') {
						field[i][j] = '.';
						if(i - 1 >= 0 && field[i - 1][j] != '*' && field[i - 1][j] != '.') field[i - 1][j] = '*';
						if(i + 1 < N && field[i + 1][j] != '*' && field[i + 1][j] != '.') field[i + 1][j] = '*';
						if(j - 1 >= 0 && field[i][j - 1] != '*' && field[i][j - 1] != '.') field[i][j - 1] = '*';
						if(j + 1 < M && field[i][j + 1] != '*' && field[i][j + 1] != '.') field[i][j + 1] = '*';
					}
					if(field[i][j] == '*') {
						values[i][j] += 1;
					}
				}
			}
		}
		return field;
	}
};

<%:testing-code%>
// Powered by FileEdit