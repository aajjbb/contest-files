#include <bits/stdc++.h>

template<typename T> T gcd(T a, T b) {
  if(!b) return a;
  return gcd(b, a % b);
}
template<typename T> T lcm(T a, T b) {
  return a * b / gcd(a, b);
}

template<typename T> void chmin(T& a, T b) { a = (a > b) ? b : a; }
template<typename T> void chmax(T& a, T b) { a = (a < b) ? b : a; }
int in() { int x; scanf("%d", &x); return x; }

using namespace std;

typedef long long Int;
typedef unsigned uint;

class FlightDataRecorder {
public:
	double getDistance(vector <int>, vector <int>);
};

double FlightDataRecorder::getDistance(vector <int> heading, vector <int> distance) {
	double x = 0.0;
	double y = 0.0;

	const int N = (int) heading.size();
	const double PI = acos(-1);

	for (int i = 0; i < N; i++) {
		x += cos(heading[i] / 180.0 * PI) * distance[i];
		y += sin(heading[i] / 180.0 * PI) * distance[i];
	}

  return hypot(x, y);
}
<%:testing-code%>
   //Powered by [KawigiEdit] 2.0!
