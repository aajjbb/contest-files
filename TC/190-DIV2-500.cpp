// 10-17-2013 01:11:22+01:00	Submit	aajjbb	500	445.31
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

class Hangman {
public:
	string guessWord(string, vector <string>);
};

string Hangman::guessWord(string feedback, vector <string> words) {
	int i, j;
	int N = (int) words.size();
	int M = (int) feedback.size();

	char c;

	vector<string> ans;

	for (i = 0; i < N; i++) if (words[i].size() == feedback.size()) {
		bool ok = true;
		for (j = 0; j < M; j++) {
			if (feedback[j] != '-' && feedback[j] != words[i][j]) {
				ok = false;
			}
		}
		for (c = 'A'; c <= 'Z'; c++) if (feedback.find(c) != string::npos) {
			for (j = 0; j < M; j++) {
				if (words[i][j] == c && feedback[j] != c) {
					ok = false;
				}
			}
		}
		if (ok) ans.push_back(words[i]);
	}

	if (1 != ans.size()) {
		return "";
	} else {
		return ans[0];
	}
}

//Powered by [KawigiEdit] 2.0!