// 11-24-2014 02:53:35+01:00	Submit	aajjbb	500	150.00
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

class RoadsAndFools {
public:
	string determineOrientation(int, vector <int>);
};

string vecToString(vector<int> vs) {
	int N = (int) vs.size();
	string ans;

	for (int i = 0; i < N; i++) {
		if (i > 0) {
			ans += " ";
		}
		ans += to_string(vs[i]);
	}

	return ans;
}

string RoadsAndFools::determineOrientation(int length, vector <int> frontSides) {
	int N = (int) frontSides.size();

	frontSides[0] = min(frontSides[0], length - frontSides[0]);

	if (N == 1) {
		if (frontSides[0] * 2 == length) {
			return vecToString(frontSides);
		} else {
			return "MULTIPLE SOLUTIONS";
		}
	}

	bool multiple = false;

	for (int i = 1; i < N; i++) {
		int l = min(frontSides[i], length - frontSides[i]);
		int h = max(frontSides[i], length - frontSides[i]);

		if (l > frontSides[i - 1]) {
			frontSides[i] = l;
		} else if (h > frontSides[i - 1]) {
			frontSides[i] = h;
		} else {
			cout << vecToString(frontSides) << "\n";
			return "NO SOLUTION";
		}
	}

	for (int i = 0; i < N; i++) {
		int ch = length - frontSides[i];

		if (ch == frontSides[i]) continue;

		if ((i == 0 && ch < frontSides[i + 1]) || (ch > frontSides[i - 1] && (i == N - 1 || ch < frontSides[i + 1]))) {
			multiple = true;
		}
	}
	if (multiple) {
		return "MULTIPLE SOLUTIONS";
	} else {
		return vecToString(frontSides);
	}
}

//Powered by [KawigiEdit] 2.0!
