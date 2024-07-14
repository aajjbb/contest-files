// 03-10-2013 21:47:11+01:00	Submit	aajjbb	500	433.14
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

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR(i, a, n) for(int i = a; i < n; i++)
#define REV(i, a, n) for(int i = a; i > n; i--)

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

typedef long long ll;
typedef long double ld;

struct Animation {
	vector <string> animate(int speed, string init) {
		int N = init.size();
		vector<string> ans;
		vector<char> situation[N];

		string now = string(N, '.');

		REP(i, N) if(init[i] != '.') {
			now[i] = 'X';
			situation[i].push_back(init[i]);
		}

		while(now.find("X") != string::npos) {
			ans.push_back(now);
			now = string(N, '.');

			vector<char> next_sit[N];

			REP(i, N) if(!situation[i].empty()) {
				REP(j, situation[i].size()) {
					char go = situation[i][j];
					if(go == 'L' && i - speed >= 0) {
						now[i-speed] = 'X';
						next_sit[i-speed].push_back('L');
					} else if(go == 'R' && i + speed < N) {
						now[i+speed] = 'X';
						next_sit[i+speed].push_back('R');
					}
				}
			}
			REP(i, N) situation[i] = next_sit[i];
		}
		ans.push_back(string(N, '.'));
		return ans;
	}
};


// Powered by FileEdit
