/* aajjbb */
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
#include <numeric>
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

#define REP(i, n) for(int (i) = 0; i < n; i++)
#define FOR(i, a, n) for(int (i) = a; i < n; i++)
#define FORR(i, a, n) for(int (i) = a; i <= n; i++)
#define sz(n) n.size()
#define pb(n) push_back(n)
#define all(n) n.begin(), n.end()

template<typename T> T gcd(T a, T b) {
    if(!b) return a;
    return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
    return a * b / gcd(a, b);
}

using namespace std;

typedef long long ll;
typedef long double ld;

struct LISNumberDivTwo {
	int calculate(vector <int> seq) {
		int i, j, ans = 0, N = seq.size();

		for (i = 0; i < N; i++) {
			j = i + 1;
			priority_queue<int> q; q.push(seq[i]);
			cout << seq[i] << " ";
			while (j < N && seq[j] > q.top()) {
				q.push(seq[j]); j += 1;
				cout << seq[j] << " ";
			}
			cout << "\n";
			ans += 1;
			i = j - 1;
		}

		return ans;
	}
};

// Powered by FileEdit
