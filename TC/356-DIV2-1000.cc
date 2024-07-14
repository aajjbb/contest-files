// 10-12-2012 20:31:09+01:00	Submit	aajjbb	1000	679.37
/*aajjbb*/
#line 80 "RoadReconstruction.cpp"
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

vector<string> split(string s) {
	istringstream ss(s);
	vector<string> ans;
	string buff;

	while(ss >> buff) {
		ans.push_back(buff);
	}
	return ans;
}

struct UnionFind {
	int n, *id, *size;

	UnionFind(int _n) {
		n = _n;
		id = new int[n];
		size = new int[n];

		for(int i = 0; i < n; i++) {
			id[i] = i;
			size[i] = 1;
		}
	}

	int root(int i) {
		while(i != id[i]) {
            id[i] = id[id[i]];
            i = id[i];
        }
        return i;
	}

	bool find(int p, int q) {
		return root(p) == root(q);
	}

	void unite(int p, int q) {
		int i = root(p);
        int j = root(q);
        if(i == j) return;
        if(size[i] < size[j]) {
            id[i] = j; size[j] += size[i];
        } else {
            id[j] = i; size[i] += size[j];
        }
	}
};

struct road {
	string id;
	int u, v, cost;

	bool operator<(const road& r) const {
		if(cost != r.cost) return cost < r.cost;
		return id < r.id;
	}
};


struct RoadReconstruction {
	string selectReconstruction(vector <string> roads) {
		int i, base = 1, all = 0;
		string ans;

		vector<road> vr;
		map<string, int> msi;

		REP(i, roads.size()) {
			vector<string> s = split(roads[i]);
			if(msi[s[1]] == 0) { msi[s[1]] = base++; all += 1; }
			if(msi[s[2]] == 0) { msi[s[2]] = base++; all += 1; }
			road r;
			r.id = s[0];
			r.u = msi[s[1]];
			r.v = msi[s[2]];
			if(s.size() == 3) {
				r.cost = 0;
			} else {
				r.cost = atoi(s[3].c_str());
			}
			vr.push_back(r);
		}
		set<int> check;
		vector<string> vs;
		sort(vr.begin(), vr.end());
		UnionFind uf(all+1);
		REP(i, vr.size()) {
			if(!uf.find(vr[i].u, vr[i].v)) {
				uf.unite(vr[i].u, vr[i].v);
				if(vr[i].cost != 0) {
					vs.push_back(vr[i].id);
				}
			}
		}
		REP(i, roads.size()) {
			vector<string> s = split(roads[i]);
			check.insert(uf.root(msi[s[1]]));
			check.insert(uf.root(msi[s[2]]));
		}
		if(check.size() != 1) return "IMPOSSIBLE";
		sort(vs.begin(), vs.end());
		REP(i, vs.size()) {
			ans += vs[i];
			if(i != vs.size() - 1) ans += " ";
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit