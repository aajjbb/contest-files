#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <climits>

using namespace std;

class LayeredGlass {
public:
	int minDefects(vector <string>, vector <string>);
};

// rotates clockwise
vector<string> rotate(const vector<string>& table) {
	const int N = table.size();
	const int M = table[0].size();

	vector<string> rot(N, string(M, ' '));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			rot[M - j - 1][i] = table[i][j];
		}
	}

	return rot;
}

// rotates clockwise
vector<string> mirror(const vector<string>& table) {
	const int N = table.size();
	const int M = table[0].size();

	vector<string> rot(N, string(M, ' '));

	for (int i = 0; i < N; i++) {
		rot[i] = table[i];
		reverse(rot[i].begin(), rot[i].end());
	}

	return rot;
}

int getAnswer(const vector <string>& a, const vector <string>& b) {
	int ans = 0;

	const int N = a.size();
	const int M = a[0].size();

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 'X' || b[i][j] == 'X') {
				ans += 1;
			}
		}
	}


	return ans;
}

void print_r(vector<string> a) {
	const int N = a.size();

	for (int i = 0; i < N; i++) {
		cout << a[i] << endl;
	}
	cout << endl;
}

int LayeredGlass::minDefects(vector <string> a, vector <string> b) {
	const int MAX_ROTATE = 5;

	int ans = INT_MAX;

	vector<string> new_a = a;
	vector<string> new_b = b;

	for (int i = 0; i < MAX_ROTATE; i++) {
		for (int j = 0; j < MAX_ROTATE; j++) {
			ans = min(ans, getAnswer(new_a, new_b));
			ans = min(ans, getAnswer(new_a, mirror(new_b)));
			ans = min(ans, getAnswer(mirror(new_a), new_b));
			ans = min(ans, getAnswer(mirror(new_a), mirror(new_b)));
			new_b = rotate(new_b);
		}
		new_a = rotate(new_a);
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
