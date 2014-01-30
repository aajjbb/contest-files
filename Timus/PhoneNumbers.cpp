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

string S;
int N;

string str[50005];

vector<pair<int, int> > vp;

map<int, vector<char> > mcv;
char v[30];


struct Trie {
    Trie *child[30];
    int prefixes;
    int words;

    Trie() {
        int i;
        prefixes = words = 0;
        for(i = 0; i < 30; i++) {
            child[i] = NULL;
        }
    }

    void addWord(string s, int pos = 0) {
        int letter_pos = s[pos] - 'a';

        Trie *t = child[letter_pos];

        if(child[letter_pos] == NULL) {
            t = child[letter_pos] = new Trie();
            t->prefixes = 1;
        } else {
            t->prefixes = t->prefixes + 1;
        }
		if (pos + 1 == s.size()) {
			words++;
		} else {
			t->addWord(s, pos + 1);
		}
    }
	///////
	void find(int start, int id, int sz, string buff) {
		if (id + sz > S.size()) return;
		if (words > 0) {
			vp.push_back(make_pair(make_pair(buff + eid, id + sz));
		} 

		for (int i = 0; i < (int) mcv[start].size(); i++) {
			int next_letter = mcv[start][i] - 'a';
			
			Trie *next_pointer = child[next_letter];

			if (v[next_letter] == (int) start && next_pointer != NULL && id + sz + 1 < S.size()) {
				next_pointer->find(S[id + sz + 1] - '0', id, sz + 1, buff + (char) (next_letter + 'a'));
			}
		}
	}
};

void build(void) {
	mcv[0].push_back('o');	mcv[0].push_back('q'); 	mcv[0].push_back('z');
	mcv[1].push_back('i');	mcv[1].push_back('j');
	mcv[2].push_back('a');	mcv[2].push_back('b'); 	mcv[2].push_back('c');
	mcv[3].push_back('d');	mcv[3].push_back('e'); 	mcv[3].push_back('f');
	mcv[4].push_back('g');	mcv[4].push_back('h'); 
	mcv[5].push_back('k');	mcv[5].push_back('l');	
	mcv[6].push_back('m'); 	mcv[6].push_back('n');
	mcv[7].push_back('p');	mcv[7].push_back('r'); 	mcv[7].push_back('s');
	mcv[8].push_back('t');	mcv[8].push_back('u'); 	mcv[8].push_back('v');
	mcv[9].push_back('w');	mcv[9].push_back('x'); 	mcv[9].push_back('y');

	v[0] = 2;	v[1] = 2;	v[2] = 2;
	v[3] = 3;	v[4] = 3;	v[5] = 3;
	v[6] = 4;	v[7] = 4;	v[8] = 1;
	v[9] = 1;	v[10] = 5;	v[11] = 5;
	v[12] = 6;	v[13] = 6;	v[14] = 0;
	v[15] = 7;	v[16] = 0;	v[17] = 7;
	v[18] = 7;	v[19] = 8;	v[20] = 8;
	v[21] = 8;	v[22] = 9;	v[23] = 9;
	v[24] = 9;	v[25] = 0;
}

pair<int, string> func(int id, int last) {
	if (vp[id].second == S.size()) {
		return make_pair(0, "");
	} else {
		pair<int, string>& ans = dp[id][last];

		if (ans.first == -1) {
			ans.first = 10101010;;
			ans.second = "";

			for (int i = id + 1; i < (int) vp.size(); i++) {
				if (vp[i].first == vp[id].second + 1) {
					pair<int, int> curr = func(i, id);

					curr.first += 1;
					curr.second += " " + vp[i].second;

					if (first , ans.first) {
						ans = curr;
					}
				}
			}
		}

		return ans;
	}
}

int main(void) {
	build();

	for ( ; cin >> S && S != "-1"; ) {
		cin >> N;

		Trie T;

		for (int i = 0; i < N; i++) {
			cin >> str[i];
			T.addWord(str[i]);
		}
		vp.clear();

		for (int i = 0; i < (int) S.size(); i++) {
			T.find(S[i] - '0', i, 0, "");
		}

		for (int i = 0; i < (int) vp.size(); i++) {
			cout << vp[i].first << " " << vp[i].second << "\n";
		}
	}
    return 0;
}
