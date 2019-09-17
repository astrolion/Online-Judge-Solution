#include "bits/stdc++.h"
using namespace std;

/**
Accepted, the bug was assigning root parent as 0, as well as
initially assigning whole table as 0

https://www.spoj.com/submit/LCA/id=24408571

**/

const int N = 1005;
vector<int>g[N];
int inTime[N], outTime[N], table[N][20];
int Time;

void dfs(int node, int parent = -1) {
        inTime[node] = ++Time;
        table[node][0] = parent;

        for(int i = 1; i < 20; i++) {
                if( table[node][i - 1] + 1  )
                        table[node][i] = table[ table[node][i - 1] ][i - 1];
        }

        for(int i = 0; i < g[node].size(); i++ ) {
                if( g[node][i] != parent ) {
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

        //cout<<"here!"<<endl;

        for(int i = 19; i >= 0; i--) {
                if( !isAncestor( table[u][i], v ) & table[u][i] != -1  ) {
                        u = table[u][i];
                }
        }
        return table[u][0];
}

void check(int n) {
        for(int i = 1; i <= n; i++) {
                cout << i << " -> " << inTime[i] << " <- " << outTime[i] << endl;
        }

        for(int i = 1; i <= n; i++) {
                cout << i;
                for(int j = 0; j < 20; j++)
                        cout << " " << table[i][j];
                cout << endl;
        }
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

                memset(table, -1, sizeof table);

                dfs(1);
                check(n);

                printf("Case %d:\n", tc);
                int q; scanf("%d", &q);
                while(q--) {
                        int x, y; scanf("%d %d", &x, &y);
                        printf("%d\n", lca(x, y));
                }





        }


        return 0;
}
