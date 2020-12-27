#include <bits/stdc++.h>

using namespace std;

const int MAXN = 3030;

map<string, int> mp;
string c1, c2;
int vis[MAXN], low[MAXN], num[MAXN], sat[MAXN],dfs_counter, scc_counter ,n, test = 1;
vector<vector<int> > graph(MAXN);
stack<int> st;

//Find strongly connected components
void tarjan(int u, int depth) {
    low[u] = num[u] = depth;
    st.push(u);
    vis[u] = 1;
    for(int i = 0; i < graph[u].size(); i++) {
        int v = graph[u][i];
        if(num[v] == -1){
            tarjan(v, depth+1);
        }
        if (vis[v]){
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == depth) {
        while(1) {
            int next = st.top();st.pop();
            sat[next] = scc_counter;
            vis[next] = 0;
            if(u == next) break;
        }
        ++scc_counter;
    }
}

/*
  To use the 2-SAT property, it could be transformed in a boolean logic with AND or OR
  A | B, means !A -> B
  !A | B, means !!A -> B equals to A -> B
  A | !B means !A -> !B
  !A | !B means !!A -> !B equals to A -> !B

  "-> is an implicance to separate the usege of A AND B"

  2-sat property is YES if all the components have no disturbs, e.g.:
  If you find !A and A in the same "scc", you're talking that !A = true AND A = true, it is not right.
*/
int main(void){
    ios::sync_with_stdio(0);
    while(cin >> n){
        mp.clear();
        for(int i = 0; i < MAXN; i++){
            graph[i].clear();
            vis[i] = 0;
            num[i] = -1;
            sat[i] = -1;
            low[i] = 0;
        }
        cin.ignore();
        int index = 0;
        //Graph mount:
        for(int i = 0; i < n; i++){
            cin >> c1 >> c2;
            string tmpA, tmpB;
            bool A = 1, B = 1;
            if(c1[0] == '!'){
                tmpA = c1.substr(1);
                A = 0;
            }else{
                tmpA = c1;
            }
            if(c2[0] == '!'){
                tmpB = c2.substr(1);
                B = 0;
            }else{
                tmpB = c2;
            }
            if(mp.find(tmpA) == mp.end()){
                mp[tmpA] = index;
                index += 2;
            }
            if(mp.find(tmpB) == mp.end()){
                mp[tmpB] = index;
                index += 2;
            }
            int U = mp[tmpA] + !A, V = mp[tmpB] + !B;
            graph[U^1].push_back(V);
            graph[V^1].push_back(U);
        }

        dfs_counter = scc_counter = 0;
        for(int i = 0; i < index; i++){
            if(num[i] == -1){
                tarjan(i, 0);
            }
        }
        int win = 1;
        //Checking disturbs
        for(int i = 0; i < index && win; i += 2){
            if(sat[i^1] == sat[i]) win = 0;
        }
        printf("Instancia %d\n", test++);
        if(win){
            printf("sim\n");
        }else{
            printf("nao\n");
        }
        printf("\n");
    }
    return 0;
}
