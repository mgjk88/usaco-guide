#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    int over = 0;
    int ridx = 0;

    freopen("speeding.in", "r", stdin);
    scanf("%d %d", &n, &m);
    vector<pair<int, int>> r(n);
    for (int i = 0; i < n; i++) {
        r[i] = {};
        scanf("%d %d", &r[i].first, &r[i].second);
    }
    for (int i = 0; i < m; i++){
        int bt = 0; int bs = 0;
        scanf("%d %d", &bt, &bs);
        while(bt > 0) {
            over = max(over, bs - r.at(ridx).second);
            if(bt >= r.at(ridx).first) {
                bt -= r.at(ridx).first;
                ridx++;
            }
            else {
                r.at(ridx).first -= bt;
                break;
            }
        }
    }
    freopen("speeding.out", "w", stdout);
    printf("%d", over);
}