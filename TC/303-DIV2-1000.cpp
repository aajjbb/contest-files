// 10-15-2012 05:14:55+01:00	Submit	aajjbb	1000	533.50
#line 52 "PrimePalindromic.cpp"
/* aajjbb */
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <iostream>
#include <functional>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <valarray>
#include <vector>
#include <utility>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

template <class T> void make_unique(T& v) {sort(all(v)); v.resize(unique(all(v)) - v.begin());}

#define REP(i, n) for((i) = 0; (i) < (n); i++)
#define FOR(i, a, n) for((i) = (a); (i) < (n); i++)

using namespace std;

const int INF = 1000000000;
const double PI = acos(-1);

typedef long long ll;

const int MAX = 10000;

vector<int> get_primes() {
	vector<int> ans;
	vector<bool> check(MAX+1, true);

	check[0] = check[1] = false;

	for(int i = 2; i <= (int) sqrt(MAX); i++) if(check[i]) {
		for(int j = i * i; j <= MAX; j += i) {
			check[j] = false;
		}
	}
	for(int i = 2; i <= MAX; i++) if(check[i]) ans.push_back(i);
	return ans;
}

vector<int> func(vector<int>& primes, int num) {
	vector<int> ans;
	for(int i = 0; i < primes.size(); i++) {
		while(num % primes[i] == 0 && num > 0) {
			ans.push_back(primes[i]);
			num /= primes[i];
		}
	}
	return ans;
}

bool isPalindrome(string s) {
	for(int i = 0; i < s.size(); i++) if(s[i] != s[s.size()-i-1]) return false;
	return true;
}

string int_to_str(int x) {
	string ans = "";
	while(x > 0) {
		ans += (x % 10) + '0';
		x /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool func2(vector<int>& div) {
	do {
		string s = "";
		for(int i = 0; i < div.size(); i++) s += int_to_str(div[i]);
		if(isPalindrome(s)) return true;
	} while(next_permutation(div.begin(), div.end()));
	return false;
}

struct PrimePalindromic {
	int count(int A, int B) {
		int ans = 0;
		vector<int> primes = get_primes();

		for(; A <= B; A++) {
			vector<int> help = func(primes, A);
			if(func2(help)) ans += 1;
		}

		return ans;
	}
};


// Powered by FileEdit
