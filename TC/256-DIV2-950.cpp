#line 82 "GraphLabel.cpp"
/*
 aajjbb
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <functional>
#include <valarray>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <climits>

using namespace std;

#define REP(i, n) for(i = 0; i < (n); i++)
#define FOR(i, a, n) for(i = a; i < n; i++)
#define REV(i, a, n) for(i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct GraphLabel {
	int adjacentDifference(vector <string> graph) {
		int i, j, m = 100000000, N = graph.size();
		vector<int> count;
		REP(i, N) count.push_back(i);
		do {
			int tmp = 0;
			REP(i, N) {
				REP(j, N) {
					if(graph[i][j] == '1') {
						tmp = max(tmp, abs(count[i] - count[j]));
					}
				}
			}
			m = min(m, tmp);
		} while(next_permutation(count.begin(), count.end()));
		return m;
	}
};

// Powered by FileEdit
