#include "bits/stdc++.h"
using namespace std;

const int N = 1e5 + 5;
int cnt[N];

int main() {

        int t; scanf("%d", &t);

        for(int tc = 1; tc <= t; tc++) {
                int pages, tons, readers;
                cin >> pages >> tons >> readers;

                vector<int>bad(tons);
                vector<int>users(readers);

                for(auto &it : bad) cin >> it;
                for(auto &it : users) cin >> it;

                memset( cnt, 0, sizeof cnt );


                for(auto it : bad) {

                        int sq = sqrt(it);
                        for(int i = 1; i <= sq; i++) {
                                if(it % i == 0) {
                                        cnt[i]++;
                                        if(i*i == it){

                                        }
                                        else{
                                                cnt[it/i]++;
                                        }

                                }
                        }


                }

                long long ans = 0LL;

                for(auto it : users) {
                        int d = pages / it;
                        long long lage = d - cnt[it];
                        ans += lage;
                }

                printf("Case #%d: %lld\n", tc, ans);





        }


        return 0;
}
