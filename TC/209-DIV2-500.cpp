// 02-03-2015 01:06:32+01:00	Submit	aajjbb	500	150.00
#line 57 "MedalTable.cpp"
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

struct pais {
	string nome;
	int g, p, b;
	pais(){}
	pais(string nome, int g, int p, int b): nome(nome), g(g), p(p), b(b){}
	bool operator<(const pais& pa) const {
		if(g != pa.g) return g > pa.g;
		if(p != pa.p) return p > pa.p;
		if(b != pa.b) return b > pa.b;
		return nome < pa.nome;
	}
};

string int_to_str(int x) {
	string ans = "";
	if(x == 0) return "0";
	while(x > 0) {
		ans = ans + (char) ((x % 10) + '0');
		x /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

struct MedalTable {
	vector <string> generate(vector <string> results) {
		int i, j;
		vector<pais> vp;
		REP(i, results.size()) {
			string g = results[i].substr(0, 3); bool has_g = false;
			string p = results[i].substr(4, 3); bool has_p = false;
			string b = results[i].substr(8, 3);	bool has_b = false;
			REP(j, vp.size()) {
				if(vp[j].nome == g) {
					has_g = true;
					vp[j].g += 1;
				}
			}
			if(!has_g) vp.push_back(pais(g, 1, 0, 0));
			REP(j, vp.size()) {
				if(vp[j].nome == p) {
					has_p = true;
					vp[j].p += 1;
				}
			}
			if(!has_p) vp.push_back(pais(p, 0, 1, 0));
			REP(j, vp.size()) {
				if(vp[j].nome == b) {
					has_b = true;
					vp[j].b += 1;
				}
			}
			if(!has_b) vp.push_back(pais(b, 0, 0, 1));
		}
		sort(vp.begin(), vp.end());
		vector<string> ans;
		REP(i, vp.size()) {
			string got = "";
			got += vp[i].nome + " ";
			got += int_to_str(vp[i].g) + " ";
			got += int_to_str(vp[i].p) + " ";
			got += int_to_str(vp[i].b);
			ans.push_back(got);
		}
		return ans;
	}
};


// Powered by FileEdit
