// 02-14-2012 16:16:28+01:00	Submit	aajjbb	250	227.29
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

class FowlRoad {
	public:
	int crossings(int roadY, vector <int> bobX, vector <int> bobY)  {
		int p = 0;
		vector<int> nx, ny;

		for(int i = 0; i < bobX.size(); i++) if(bobY[i] != roadY) { nx.push_back(bobX[i]); ny.push_back(bobY[i]); }

		for(int i = 0; i < nx.size() - 1; i++) {
			if((ny[i] < roadY && ny[i + 1] > roadY) || (ny[i] > roadY && ny[i + 1] < roadY)) p++;
		}
		return p;
	}
};


<%:testing-code%>
// Powered by FileEdit