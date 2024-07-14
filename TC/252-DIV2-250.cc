// 09-02-2012 21:05:15+01:00	Submit	aajjbb	250	205.27
#line 85 "WarCry.cpp"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class WarCry {
	public:
	int alertTime(string outposts) {
		int i, ans = 0, n = outposts.size();
		while(1) {
			bool change = false;
			vector<bool> now(n, false);
			for(i = 0; i < n; i++) {
				if(outposts[i] == 'x' && !now[i]) {
					if(i - 1 >= 0 && outposts[i - 1] != 'x') {
						outposts[i - 1] = 'x';
						now[i - 1] = true;
						change = true;
					}
					if(i + 1 < n && outposts[i + 1] != 'x') {
						outposts[i + 1] = 'x';
						now[i + 1] = true;
						change = true;
					}
				}
			}
			if(change) ans += 1;
			else break;
		}
		return ans;
	}
};

<%:testing-code%>
// Powered by FileEdit