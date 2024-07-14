// 12-11-2013 01:57:50+01:00	Submit	aajjbb	500	280.51
#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

class OmahaLow {
public:
	string low(string, string);
};

map<char, int> rk;

bool cmp(char a, char b) {
	return rk[a] < rk[b];
}

struct scmp {
	bool operator()(string a, string b) {
		int i;

		for (i = 0; i < 5; i++) {
			if (a[i] != b[i]) {
				return rk[a[i]] > rk[b[i]];
			}
		}

		return true;
	}
};

void build(void) {
	rk['1'] = 1;
	rk['2'] = 2;
	rk['3'] = 3;
	rk['4'] = 4;
	rk['5'] = 5;
	rk['6'] = 6;
	rk['7'] = 7;
	rk['8'] = 8;
	rk['9'] = 9;
	rk['T'] = 10;
	rk['J'] = 11;
	rk['Q'] = 12;
	rk['K'] = 13;
}

string OmahaLow::low(string sharedCards, string playersCards) {
	int i, j, k;
	string ans = "";

	build();

	priority_queue<string, vector<string>, scmp> pq;

	for (i = 0; i < (1 << 5); i++) {
		for (j = 0; j < (1 << 4); j++) {
			if (__builtin_popcount(i) == 3 && __builtin_popcount(j) == 2) {
				string now = "";

				set<char> cs;

				for (k = 0; k < 5; k++) if (1 & (i >> k)) {
					now += sharedCards[k];
					cs.insert(sharedCards[k]);
				}
				for (k = 0; k < 4; k++) if (1 & (j >> k)) {
					now += playersCards[k];
					cs.insert(playersCards[k]);
				}

				sort(now.rbegin(), now.rend(), cmp);

				if (rk[now[0]] <= 8 && cs.size() == 5) {
					pq.push(now);
				}
			}
		}
	}

	if (!pq.empty()) ans = pq.top();

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!