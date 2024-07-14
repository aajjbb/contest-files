// 09-22-2012 18:03:32+01:00	Submit	aajjbb	900	423.19
/*
 aajjbb
*/
#line 76 "DivisorInc.cpp"
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
#define for_each(q, s) for(typeof(s.begin()) q=s.begin(); q!=s.end(); q++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

using namespace std;

typedef long long ll;
typedef long double ld;

struct DivisorInc {
 	int countOperations(int N, int M) {
 		int i;
 		set<int> heap;
 		vector<int> dist(100010, INT_MAX);
 		set<int>::iterator it;

 		FOR(i, 2, sqrt(N)+1) {
 			if(N % i == 0) {
 				heap.insert(i);
 			}
 		}
 		queue<int> q;
 		q.push(N);
 		dist[N] = 0;

 		while(!q.empty()) {
 			int p = q.front(); q.pop();
 			for(i = 2; i * i <= p; i++) {
 				if(p % i == 0) {
 					if(p + i <= 100000 && dist[p+i] == INT_MAX) {
 						q.push(p+i);
 						dist[p+i] = dist[p] + 1;
 					}
 					if(p + p/i <= 100000 && dist[p+p/i] == INT_MAX) {
 						q.push(p+p/i);
 						dist[p+p/i] = dist[p] + 1;
 					}

 				}
 			}
 		}
 		return dist[M] == INT_MAX ? -1 : dist[M];
	}
};

<%:testing-code%>
// Powered by FileEdit