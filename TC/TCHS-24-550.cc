// Submitted in 19-11-2018 : 13:05

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

using namespace std;


class AnagramCompletion {
public:
	vector <string> complete(string word1, string word2) {
		map<char, int> cnt_w1, cnt_w2;

		for (char c: word1) {
			cnt_w1[c] += 1;
		}

		for (char c: word2) {
			cnt_w2[c] += 1;
		}

		for (char curr_char = 'Z'; curr_char >= 'A'; curr_char--) {
			if (cnt_w1[curr_char] == cnt_w2[curr_char]) {
				continue;
			}

			int goal = max(cnt_w1[curr_char], cnt_w2[curr_char]);

			while (cnt_w1[curr_char] < goal) {
				bool added = false;

				for (int i = word1.size() - 1; i >= 0; i--) {
					if (word1[i] == '.') {
						word1[i] = curr_char;
						cnt_w1[curr_char] += 1;
						added = true;
						break;
					}
				}

				if (!added) break;
			}
			while (cnt_w2[curr_char] < goal) {
				bool added = false;

				for (int i = word2.size() - 1; i >= 0; i--) {
					if (word2[i] == '.') {
						word2[i] = curr_char;
						cnt_w2[curr_char] += 1;
						added = true;
						break;
					}
				}

				if (!added) break;
			}
		}

		for (int i = 0; i < word1.size(); i++) {
			if (word1[i] == '.') {
				word1[i] = 'A';
				}
		}
		for (int i = 0; i < word2.size(); i++) {
			if (word2[i] == '.') {
				word2[i] = 'A';
			}
		}

		vector<string> ans;

		string cpy_w1 = word1;
		string cpy_w2 = word2;

		sort(cpy_w1.begin(), cpy_w1.end());
		sort(cpy_w2.begin(), cpy_w2.end());

		if (cpy_w1 == cpy_w2) {
			ans.push_back(word1);
			ans.push_back(word2);
		}
		return ans;
	}
};

//Powered by KawigiEdit-pf 2.3.0!
