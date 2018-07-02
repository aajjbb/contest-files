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
typedef unsigned long long uInt;
typedef unsigned uint;

const int MAXN = 200005;

int N;

struct event {
	long long op, ed;
    bool is_open;

    event(){}
    
    event(long long _op, long long _ed, bool _is_open) {
		op = _op;
        ed = _ed;
        is_open = _is_open;
    }

    bool operator<(const event& other) const {
        if (is_open) {
			return op < other.op;
        } else {
			return ed > other.ed;
        }
    }
};

int main(void) {
    cin >> N;

    vector<event> events;
    vector<int> count(N + 1, 0);

    map<pair<long long, long long>, int> cnt_pairs;
    
    for (int i = 0; i < N; i++) {
		int l, r;
        cin >> l >> r;

    	cnt_pairs[make_pair(l, r)] += 1;
        
		events.push_back(event(l, r, true));
   		events.push_back(event(l, r, false));
    }

    sort(events.begin(), events.end());

    int curr = 0;
    
	for (int i = 0; i < (int) events.size(); i++) {
		if (events[i].is_open) {
            pair<long long, long long> cp = make_pair(events[i].op, events[i].ed);
            
			curr += cnt_pairs[cp];
            cnt_pairs[cp] = 0;
        } else {
			count[curr] += (events[i].ed - events[i].op) + 1;            
        }
    }
    
    
    return 0;
}
