// 2020-05-30T18:59:15+01:00
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

using namespace std;

class TwoWords {
public:
	string howMany(string, string, string);
};

bool canBoth(string statement, string word1, string word2) {
	for (int i = 0; i + word1.size() <= statement.size(); i++) {
		for (int j = i + word1.size(); j + word2.size() <= statement.size(); j++) {
			bool valid1 = true;
			bool valid2 = true;

			for (int k = 0; k < word1.size(); k++) {
				if (statement[i + k] == '?' || word1[k] == '?') {
					continue;
				}
				if (statement[i + k] != word1[k]) {
					valid1 = false;
				}
			}

			for (int k = 0; k < word2.size(); k++) {
				if (statement[j + k] == '?' || word2[k] == '?') {
					continue;
				}
				if (statement[j + k] != word2[k]) {
					valid2 = false;
				}
			}

			if (valid1 && valid2) {
				return true;
			}
		}
	}

	return false;
}

bool canSingle(string statement, string word) {
	for (int i = 0; i + word.size() <= statement.size(); i++) {
		bool valid = true;

		for (int k = 0; k < word.size(); k++) {
			if (statement[i + k] == '?' || word[k] == '?') {
				continue;
			}
			if (statement[i + k] != word[k]) {
				valid = false;
			}
		}


		if (valid) {
			return true;
		}
	}

	return false;
}

string TwoWords::howMany(string statement, string word1, string word2) {
	if (canBoth(statement, word1, word2) || canBoth(statement, word2, word1)) {
		return "both";
	} else if (canSingle(statement, word1) || canSingle(statement, word2)) {
		return "one";
	} else {
		return "none";
	}
}

//Powered by [KawigiEdit] 2.0!
