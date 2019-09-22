#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
const int LOG = 20;
int parent[N][LOG + 1];
int n, m;

vector< int > g[N], save[N];

int Time, inTime[N], outTime[N], depth[N];

void dfs( int node, int dep ) {
        inTime[node] = ++Time;
        depth[node] = dep;

        for(auto x : g[node]) dfs(x, dep + 1);

        outTime[node] = Time;

}


int main() {

        scanf("%d", &n);

        for(int i = 1; i <= n; i++) {
                scanf("%d", &parent[i][0]);
                g[ parent[i][0] ].push_back(i);
        }

        for(int i = 1; i < LOG; i++) {
                for(int j = 0; j <= n; j++) {
                        if( parent[ parent[j][i - 1] ][i - 1] ) {
                                parent[i][j] = parent[ parent[j][i - 1] ][i - 1];
                                continue;
                        }
                        parent[i][j] = 0;
                }
        }

        dfs(0, 0);

        for(int i = 0; i <= n; i++) {
                save[ depth[i] ].push_back( inTime[i] );
        }

        for(int i = 0; i <= n; i++) {
                sort( save[i].begin(), save[i].end() );
        }




        scanf("%d", &m);

        while(m--) {

                int node, pos; scanf("%d %d", &node, &pos);

                if(depth[node] <= pos) {
                        printf("0 ");
                        continue;
                }

                int ances = node;

                for(int i = LOG; i >= 0; i--) {
                        if( pos & ( 1 << i ) ) {
                                ances = parent[ances][i];
                        }
                }

                int ans = upper_bound( save[ depth[node] ].begin(), save[ depth[node] ].end(), outTime[ances] )
                          - lower_bound( save[ depth[node] ].begin(), save[ depth[node] ].end(), inTime[ances] );
                ans--;

                printf("%d ", ans);



        }


        return 0;
}
