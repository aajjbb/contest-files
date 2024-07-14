// 09-04-2012 19:49:27	Submit	aajjbb	500	492.17
#line 52 "VoteRigging.cpp"
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

struct VoteRigging {
	int minimumVotes(vector <int> votes) {
		int check = votes[0], m = 0;
		if(votes.size() == 1) return 0;
		vector<int> novo(votes.begin() + 1, votes.end());
		while(1) {
			sort(novo.begin(), novo.end());
			if(novo[novo.size()-1] < check) break;
			novo[novo.size()-1] -= 1;
			check += 1; m += 1;
		}
		return m;
	}
};

<%:testing-code%>
// Powered by FileEdit