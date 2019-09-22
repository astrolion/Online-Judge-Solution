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

        outTime[node] = ++Time;

}

void show_table() {

        for(int i = 1; i <= n; i++) {
                cout << i << ": ";
                for(int ii = 0; ii <= 10; ii++) {
                        cout << " " << parent[i][ii];
                }
                cout << endl;
        }
}


int main() {

        scanf("%d", &n);

        for(int i = 1; i <= n; i++) {
                scanf("%d", &parent[i][0]);
                g[ parent[i][0] ].push_back(i);
        }

        //show_table();

        for(int log = 1; log < LOG; log++) {
                for(int i = 0; i <= n; i++) {
                        if( parent[i][log - 1] == 0 ) {
                                parent[i][log] = 0;
                        } else {
                                parent[i][log] = parent[ parent[i][log - 1] ][log - 1];
                        }
                }

        }

        //show_table();

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
