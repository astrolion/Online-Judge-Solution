#include "bits/stdc++.h"
using namespace std;

/**
Accepted, the bug was assigning root parent as 0, as well as
initially assigning whole table as 0

https://www.spoj.com/submit/LCA/id=24408571

**/

const int N = 1005;
vector<int>g[N];

/**
LCA struct

**/

struct LCA {

        int Time, n, root, LOG2 ;
        vector<int>inTime, outTime;
        vector< vector<int> >table;

        LCA(int root, int n) {
                this->n = n;
                this->root = root;
                inTime.resize(n + 1, 0);
                outTime.resize(n + 1, 0);
                LOG2 = log2(n) + 1;
                table.resize(n + 1, vector<int>(LOG2, -1) );
                dfs(root);

        }

        void dfs(int node, int parent = -1) {
                inTime[node] = ++Time;
                table[node][0] = parent;

                for(int i = 1; i < LOG2; i++) {
                        if( table[node][i - 1] + 1 ) {
                                table[node][i] = table[ table[node][i - 1] ][i - 1];
                        }
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

        int getLCA(int u, int v) {
                if(isAncestor(u, v)) return u;
                if(isAncestor(v, u)) return v;

                for(int i = LOG2 - 1; i >= 0; i--) {
                        if( table[u][i] != -1 && !isAncestor(table[u][i], v) ) {
                                u = table[u][i];
                        }
                }

                return table[u][0];

        }



};



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

                LCA astro(1,n);


                printf("Case %d:\n", tc);
                int q; scanf("%d", &q);
                while(q--) {
                        int x, y; scanf("%d %d", &x, &y);


                        printf("%d\n",  astro.getLCA(x,y) );
                }





        }


        return 0;
}
