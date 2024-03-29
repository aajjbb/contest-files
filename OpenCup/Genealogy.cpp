#include <bits/stdc++.h>
#define MAXN 100003

using namespace std;

vector<vector<pair<int,int> > > g(MAXN);
int cnt[MAXN], prev[MAXN], chainNode[MAXN], chainHead[MAXN], posInChain[MAXN], base[MAXN], level[MAXN], chainIdx, idxSegTree;
int H[MAXN], L[MAXN << 1], E[MAXN << 1], idx;
 
struct LCA{        
    int tree[MAXN * 8];
    LCA(int root, int n){
        build(1, 0, 2*n-1);
    }
 
    //NlogN build the segtree and minimize the height of the I'th visited node
    void build(int node, int l, int r){
        if(l > r) return;
        if(l == r){
            tree[node] = l;
        }else{
            int mid = (l+r) >> 1;
            build(node*2, l, mid);
            build(node*2+1, mid+1, r);
            int A = tree[node*2];
            int B = tree[node*2+1];
            if(L[A] <= L[B]){
                tree[node] = A;
            }else{
                tree[node] = B;
            }
        }
    }
 
    //Get the vertex with the minimum height, then it will be the LCA of A and B.
    int rmq(int node, int l, int r, int ra, int rb){
        if(l > rb || r < ra){
            return -1;
        }else if(l >= ra && r <= rb){
            return tree[node];
        }else{
            int mid = (l+r) >> 1;
            int q1 = rmq(node*2, l, mid, ra, rb);
            int q2 = rmq(node*2+1, mid+1, r, ra, rb);
            if(q1 == -1){
                return q2;
            }else if(q2 == -1){
                return q1;
            }else{
                if(L[q1] <= L[q2]){
                    return q1;
                }else{
                    return q2;
                }
            }
        }
    }
 
    int getLCA(int u, int v, int n){
        int goFrom = H[u];
        int goTo = H[v];
        if(goFrom > goTo){
            swap(goFrom, goTo);
        }
        return E[rmq(1, 0, 2*n-1, goFrom, goTo)]; //is the LCA of A and B;
    }
};
 
//Decompose the tree into chains
void HLD(int node, int cost, int parent){
    if(chainHead[chainIdx] == -1){
        chainHead[chainIdx] = node;
    }
    chainNode[node] = chainIdx;
    posInChain[node] = idxSegTree;
    base[idxSegTree++] = cost;
    int nodeHeavy = -1, nextCost;
    //seeking the special child (the one with most childs on the subtrees)
    for(int i = 0; i < g[node].size(); i++){
        int next = g[node][i].first;
        if(next != parent && (nodeHeavy == -1 || cnt[next] > cnt[nodeHeavy])){
            nodeHeavy = next;
            nextCost = g[node][i].second;
        }
    }
    if(nodeHeavy > -1){
        //expanding the current chain
        HLD(nodeHeavy, nextCost, node);
    }
       
    for(int i = 0; i < g[node].size(); i++){
        int next = g[node][i].first;
        if(next != nodeHeavy && next != parent){
            chainIdx++;
            HLD(next, g[node][i].second, node);
        }
    }
 
}
 
void dfsCnt(int node, int parent, int depth = 0){
    if(H[node] == -1) H[node] = idx;//mark first time the i'th node is visited
    L[idx] = depth;//when you visit a node you should mark the the depth you have found it.
    E[idx++] = node;//the i'th recursion, global variable
    level[node] = depth;
    cnt[node] = 1;
    for(int i = 0; i < g[node].size(); i++){
        int next = g[node][i].first;
        if(next != parent){
            prev[next] = node;
            dfsCnt(next, node, depth + 1);
            cnt[node] += cnt[next];
            L[idx] = depth;
            E[idx++] = node;
        }
    }      
}

int range[MAXN];

int walkChain(int U, int V){
    int ans = 0;
    bool ok = 0;
    while(chainNode[U] != chainNode[V]){
        ok = 1;
        //cout << "In chain " << chainNode[U] << endl;
        int Left = posInChain[chainHead[chainNode[U]]];
        int Right = posInChain[U];
        //cout << Left << " " << Right << endl;
        if(range.find(chainNode[U]) == range.end()){
            range[chainNode[U]] = Right;
            ans += Right - Left + 1;
        }else{
            if(Right > range[chainNode[U]]){
                ans += Right - range[chainNode[U]];
                range[chainNode[U]] = max(range[chainNode[U]], Right);
            }
            break;
        }
        U = prev[chainHead[chainNode[U]]];
    }
  
    int Left = posInChain[chainHead[chainNode[U]]];
    int Right = posInChain[U];
    if(range.find(chainNode[U]) == range.end()){
        ans += Right - Left + 1;
        range[chainNode[U]] = Right;
        //cout << "from " << Right << " " << Left << endl;
    }else{
        if(Right > range[chainNode[U]]){
            ans += Right - range[chainNode[U]];
            range[chainNode[U]] = max(range[chainNode[U]], Right);
        }
    }
  
    return ans;
}

 
void add(int a, int b, int c){
    g[a].push_back(make_pair(b,c));
    g[b].push_back(make_pair(a,c));
}
 
int n, q, Ksize, k, from[MAXN], to[MAXN], cost[MAXN], cara;

int root;

int main(void){
    freopen("genealogy.in", "r", stdin);
    freopen("genealogy.out", "w", stdout);
    scanf("%d", &n);
    chainIdx = idxSegTree = idx = 0;
    for(int i = 0; i <= n; i++){
        cnt[i] = prev[i] = chainNode[i] = base[i] = level[i] = 0;
        chainHead[i] = posInChain[i] = H[i] = -1;
        g[i].clear();
    }
    memset(L,0,sizeof(L));
    memset(E,0,sizeof(E));
    for(int i = 0; i < n; i++){
        scanf("%d", &cara);
        if(cara == -1){
            root = i;
        }else{
            cara--;
            add(cara, i, 1);
        }
    }
    dfsCnt(root,-1);
    LCA lca(0,n);
    HLD(root,-1, -1);
    scanf("%d", &q);
    while(q--){
        scanf("%d", &Ksize);
        int ans = 0;
        for(int i = 0; i < Ksize; i++){
            scanf("%d", &k);
            ans += walkChain(k-1, root);
        }
        range.clear();
        printf("%d\n", ans);
    }
    return 0;
}
