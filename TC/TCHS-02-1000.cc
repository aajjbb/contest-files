// Submitted 19-11-2018

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <limits>
#include <tuple>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

string rules;
string spell;


class Wizarding {
public:
	const int MOD = 77077;

	string ans;
	int best_value;

	int value(char c) {
		return 1 + (c - 'A');
	}

	void rec(int pos, int curr_value, string curr_str) {
		if (pos == spell.size()) {
			if (ans.empty() || curr_value > best_value ||
				(curr_value == best_value && curr_str.size() < ans.size()) ||
				(curr_value == best_value && curr_str.size() == ans.size() && curr_str < ans)) {

				best_value = curr_value;
				ans = curr_str;
			}
		} else {
			int curr_char_pos = spell[pos] - 'A';

			rec(pos + 1, curr_value, curr_str);
			rec(pos + 1, (curr_value * value(spell[pos])) % MOD, curr_str + spell[pos]);

			if (rules[curr_char_pos] != '-') {
				rec(pos + 1, (curr_value * value(rules[curr_char_pos])) % MOD, curr_str + rules[curr_char_pos]);
			}
		}
	}

	string counterspell(string spell, string rules) {
		::spell = spell;
		::rules = rules;

		rec(0, 1, "");

		return ans;
	}
};

//Powered by KawigiEdit-pf 2.3.0!
