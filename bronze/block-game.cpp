#include <bits/stdc++.h>
using namespace std;
using str = string;

vector<int> cnt(str s){
    vector<int> cnt(26);
    for(auto c:s) cnt[c - 'a']++;
    return cnt;
}

int main() {
    int n = 0;
    vector<int> alpha(26);
    freopen("blocks.in","r", stdin);
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        str first;
        str second;
        cin >> first >> second; //well, i dont get scanf for strings 
        vector<int> w1 = cnt(first);
        vector<int> w2 = cnt(second);
        for(int j = 0; j < 26; j++) alpha[j] += max(w1[j], w2[j]);
    }
    freopen("blocks.out", "w", stdout);
    for(auto i:alpha) printf("%d\n", i);
    return 0;
}