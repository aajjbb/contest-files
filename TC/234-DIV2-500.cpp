// 09-23-2014 18:57:28+01:00	Submit	aajjbb	500	485.25
#include <bits/stdc++.h>

using namespace std;

class FractionSplit {
public:
	vector <string> getSum(int, int);
};

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}

vector <string> FractionSplit::getSum(int n, int d) {
	vector<string> ans;
	char buff[20];

	for ( ; n > 0 ; ) {
		for (int i = 2; i <= d; i++) {
			int g = lcm(i, d);
			int neg = (g / d * n) - (g / i);

			if (neg >= 0) {
				d = g;
				n = neg;
				sprintf(buff, "%d/%d", 1, i);
				ans.push_back(string(buff));
				break;
			}
		}
	}

	return ans;
}

//Powered by [KawigiEdit] 2.0!
