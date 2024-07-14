// 12-09-2013 14:28:38+01:00	Submit	aajjbb	1000	999.64
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

class PrimeAnagrams {
public:
	vector <int> primes(string);
};

int toInt(string& s) {
	int i;
	int id = 0;
	int ans = 0;

	for (i = s.size() - 1; i >= 0; i--) {
		ans += pow(10, id++) * (s[i] - '0');
	}

	return ans;
}

int isPrime(int x) {
	if (x <= 1) {
		return false;
	} else if (x == 2 || x == 3) {
		return true;
	} else if (x % 2 == 0 || x % 3 == 0) {
		return false;
	} else {
		int i;

		for (i = 3; i <= (int) sqrt(x); i += 2) {
			if (x % i == 0) {
				return false;
			}
		}
	}
	return true;
}

int best = INT_MAX;
vector<int> ans;

void rec(int prod, string s, vector<int> arr) {
	if (s.empty() && arr.size() == 3) {
		sort(arr.begin(), arr.end());
		int i;
		for (i = 0; i < arr.size(); i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
		if (prod < best) {
			best = prod;
			ans = arr;
		}
	} else if (s[0] != '0') {
		int i;
		string bf = "";
		for (i = 0; i < (int) s.size(); i++) {
			bf += s[i];
			int as_int = toInt(bf);

			if (isPrime(as_int)) {
				vector<int> cp = arr;
				cp.push_back(as_int);
				rec(prod * as_int, s.substr(i + 1, s.size() - i), cp);
			}
		}
	}
}

vector <int> PrimeAnagrams::primes(string anagram) {
	sort(anagram.begin(), anagram.end());

	do {
		rec(1, anagram, vector<int>());
	} while(next_permutation(anagram.begin(), anagram.end()));

	return ans;
}
<%:testing-code%>
//Powered by [KawigiEdit] 2.0!