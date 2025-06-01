#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("gymnastics.in","r",stdin);
    int k = 0, n = 0;
    scanf("%d %d", &k, &n);
    vector<vector<int>> all(k);
    for(int i = 0; i < k; i++){
        vector<int> sesh(n);
        for(int j = 0; j < n; j++) {
            int c = 0;
            scanf("%d", &c);
            sesh[j] += c;
        }
        all[i] = sesh;
    }

    int consistent = 0;
    for(int c1 = 1; c1 < n + 1; c1++){
        for(int c2 = 1; c2 < n + 1; c2++){
            if(c1 == c2) continue;
            int cnt = 0;
            for(int s = 0; s < k; s++){
                vector<int> sesh = all.at(s);
                int fidx = find(sesh.begin(), sesh.end(), c1) - sesh.begin();
                int sidx = find(sesh.begin(), sesh.end(), c2) - sesh.begin();
                if(fidx > sidx) {
                    cnt++;
                }
            }
            if(cnt == k) consistent++;
        }
    }
    

    freopen("gymnastics.out","w",stdout);
    printf("%d", consistent);
    return 0;
}