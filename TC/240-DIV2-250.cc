// 01-23-2013 15:16:05+01:00	Submit	aajjbb	250	156.38
/*
aajjbb
*/
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

char *vowel = "aeiou";

struct Pronunciation {
	string canPronounce(vector <string> words) {
		int i;
		REP(i, words.size()) if(words[i].size() > 1) {
			if(func1(words[i]) || func2(words[i])) return words[i];
		}
		return "";
	}
	bool func1(string s) {
		int i;
		REP(i, s.size() - 2) {
			if(!isvowel(tolower(s[i])) && !isvowel(tolower(s[i+1])) && !isvowel(tolower(s[i+2]))) return true;
		}
		return false;
	}
	bool func2(string s) {
		int i;
		REP(i, s.size()-1) {
			if(tolower(s[i]) != tolower(s[i+1]) && isvowel(tolower(s[i])) && isvowel(tolower(s[i+1]))) return true;
		}
		return false;
	}
	bool isvowel(char c) {
		int i;
		REP(i, 5) if(tolower(vowel[i]) == c) return true;
		return false;
	}
};

<%:testing-code%>
// Powered by FileEdit