// Submitted - 2016:07:06 02:56:07
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
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

class CatchTheBeatEasy {
public:
	string ableToCatchAll(vector <int>, vector <int>);
};

bool cmp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

string CatchTheBeatEasy::ableToCatchAll(vector <int> x, vector <int> y) {
	int N = (int) x.size();
	vector<pair<int, int> > fruit;

	for (int i = 0; i < N; i++) {
		fruit.push_back(make_pair(x[i], y[i]));
	}

	sort(fruit.begin(), fruit.end(), cmp);

	int now_x = 0;
	int spent = 0;

	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (fruit[i].second != fruit[j].second) break;
			if (abs(now_x - fruit[i].first) > abs(now_x - fruit[j].first)) {
				swap(fruit[i], fruit[j]);
			}
		}

		int dist = abs(now_x - fruit[i].first);

		if (fruit[i].second - spent < 0 || dist > fruit[i].second - spent) {
			return "Not able to catch";
		} else {
			spent += fruit[i].second - spent;
			now_x = fruit[i].first;
		}
	}

	return "Able to catch";
}

//Powered by [KawigiEdit] 2.0!
