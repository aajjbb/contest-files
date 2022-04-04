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
    
const int MAXN = 300005;
const int LOGMAXVAL = 30;

int Y, N;
int V[MAXN];
int ptree_nodes[MAXN];

//Persistent Segment Tree
int root[MAXN]; //The root of the new node
int INDEX;
int Lef[MAXN*4*LOGMAXVAL];
int Rig[MAXN*4*LOGMAXVAL];
int S[MAXN*4*LOGMAXVAL];

struct PersistentSegTree{
    PersistentSegTree(){
		INDEX = 1;
        build(0, 0, MAXN - 1);
    }
	
	//build the initial and empty tree
    void build(int node, int l, int r){
        if(l == r){
            return;
        }else{
            int mid = (l+r) / 2;
            Lef[node] = INDEX++;
            Rig[node] = INDEX++;
            build(Lef[node], l, mid);
            build(Rig[node], mid+1, r);
        }
    }
 
	/*query to count how many elements are > K
	  here is the key of the problem.*/
    int query(int node, int l, int r, int K){
		if(r <= K){
			return 0;
		}else if(l > K){
            return S[node];
        }else{
            int mid = (l+r) / 2;
            return query(Lef[node], l, mid, K) + query(Rig[node], mid+1, r, K);
        }
    }
 
	/*add a new node, we just need to copy log(n) nodes 
	  from the previus tree add add the new one*/
    int update(int node, int l, int r, int pos){
        int next = INDEX++;
        Lef[next] = Lef[node];
        Rig[next] = Rig[node];
        S[next] = S[node];
        if(l == r){
            S[next] += 1;
        }else{
            int mid = (l+r) / 2;
            if(pos <= mid){
                Lef[next] = update(Lef[node], l, mid, pos);
            }else{
                Rig[next] = update(Rig[node], mid+1, r, pos);
            }
            S[next] = S[Lef[next]] + S[Rig[next]];
        }
        return next;
    }
};

int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin >> Y >> N;

    PersistentSegTree ptree;

    for (int i = 0; i < Y; i++) {
        cin >> V[i];

        int prev_node = i == 0 ? 0 : ptree_nodes[i - 1];

        ptree_nodes[i] = ptree.update(prev_node, 0, MAXN - 1, V[i]);
    }

    for (int i = 0; i < N; i++) {
        int a, p, f;
        cin >> a >> p >> f;

        if (p <= V[a - 1]) {
            cout << "0\n";
            continue;
        }

        int l = a - 1;
        int r = a + f - 1;
        int value = p - 1;

        int ans_a = ptree.query(ptree_nodes[l], 0, MAXN - 1, value);
        int ans_b = ptree.query(ptree_nodes[r], 0, MAXN - 1, value);

        cout << ans_b - ans_a << "\n";
    }
    return 0;
}