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

class TheJediTestDiv2 {
public:
	int countSupervisors(vector <int>, int, int);
};

int TheJediTestDiv2::countSupervisors(vector <int> students, int Y, int J) {
	int ans = 100000000;
	int jedi_cost = 0;
	int N = students.size();
	
	for (int i = 0; i < N; i++) {
		jedi_cost += (int) ceil(students[i] / (double) J);
	}
	
	for (int i = 0; i < N; i++) {
		int floor_jedi = (int) ceil(students[i] / (double) J);
		int with_yoda = (int) ceil(max(0, students[i] - Y) / (double) J);
		ans = min(ans, jedi_cost - floor_jedi + with_yoda); 
	}
	
	return ans;
}

//Powered by [KawigiEdit] 2.0!