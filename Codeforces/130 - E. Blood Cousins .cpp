#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
int parent[N];
int n, m;

vector< int > g[N];

void dfs(int node, int dep) {

        cout << node << " " << dep << endl;

        for(auto x : g[node]) {
                dfs(x, dep + 1);
        }
}

int main() {

        g[0] = {1, 4};
        g[1] = {2, 3};
        g[4] = {5, 6};

        dfs(0,0);


        scanf("%d", &n);

        for(int i = 1; i <= n; i++) {
                scanf("%d", &parent[i]);
        }

        scanf("%d", &m);

        while(m--) {
                int node, pos; scanf("%d %d", &node, &pos);



        }


        return 0;
}
