#include "bits/stdc++.h"
using namespace std;

const int N = 1005;
vector<int>g[N];
int inTime[N], outTime[N], table[N][20];
int Time;

void dfs(int node, int parent = 0) {
        inTime[node] = ++Time;
        table[node][0] = parent;

        for(int i = 1; i < 20; i++) {
                table[node][i] = table[ table[node][i - 1] ][i - 1];
        }

        for(int i = 0; i < g[node].size(); i++ ) {
                if( g[node][i] ^ parent ) {
                        dfs(g[node][i], node);
                }
        }
        outTime[node] = ++Time;
}

bool isAncestor(int u, int v) {
        return inTime[u] <= inTime[v] && outTime[u] >= outTime[v];
}

int lca(int u, int v) {
        if(isAncestor(u, v)) return u;
        if(isAncestor(v, u)) return v;

        for(int i = 19; i >= 0; i--) {
                if( !isAncestor( table[u][i], v ) & table[u][i]  ) {
                        u = table[u][i];
                }
        }
        return table[u][0];
}



int main() {

        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {

                for(int i = 0; i < N; i++) g[i].clear();

                int n; scanf("%d", &n);

                for(int i = 1; i <= n; i++) {
                        int nodes; scanf("%d", &nodes);

                        while(nodes--) {
                                int j; scanf("%d", &j);
                                g[i].push_back(j);
                                g[j].push_back(i);
                        }

                }
                Time = 0;


                dfs(1,0);

                printf("Case %d:\n", tc);
                int q; scanf("%d",&q);
                while(q--){
                        int x, y; scanf("%d %d",&x,&y);
                        printf("%d\n", lca(x,y));
                }





        }


        return 0;
}
