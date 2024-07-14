// 10-05-2012 01:08:25+01:00	Submit	aajjbb	250	249.94
#include <iostream>
#include <vector>

using namespace std;

struct Medici {
	int winner(vector<int> fame, vector<int> fortune, vector<int> secrets) {
		int ans = -1, ok = 0, N = fame.size(), check = -10000000;

		for(int i = 0; i < N; i++) {
			int less = min(fame[i], min(fortune[i], secrets[i]));

			if(less > check) {
				check = less;
				ans = i;
				ok = 0;
			} else if(less == check) {
				ok = 1;
			}
		}
		return ok ? -1 : ans;
	}
};