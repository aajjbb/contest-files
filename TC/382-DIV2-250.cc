#include <string>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct Subseq {
	int first, second, size;
	double average;

	Subseq(int f, int s, int _s, double av) {
		first = f;
		second = s;
		size = _s;
		average = av;
	}

	bool operator<(const Subseq& s) const {
		if(average == s.average) {
			if(size == s.size) {
				return first > s.first;
			}
			return size < s.size;
		} else {
			return average < s.average;
		}
	}
};

class ContiguousSubsequences {
	public:
	vector <int> findMaxAverage(vector <int> a, int K)  {
		vector<int> ans;
		vector<Subseq> v;
		int N = a.size();
		double av = 0;

		for(int i = 0; i < N; i++) {
			for(int j = 0; j <= i; j++) {
				if((i - j) + 1 >= K) {
					av = 0.0;
					for(int k = j; k <= i; k++) {
						av += a[k];
					}
					av /= (i - j) + 1;
					v.push_back(Subseq(j, i, i - j, av));
				}
			}
		}

		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());

		ans.push_back(v[0].first);
		ans.push_back(v[0].second);
		return ans;
	}
};



// Powered by FileEdit