#include <bits/stdc++.h>
using namespace std;
using str = string;
// a pair of cows are a crossing pair when betwn the entry n exit of 1 cow,
// the other cow enters but does not exit
//solution: identify start n end idx of 1 cow,
// starti < startj < endi < endj
// if so, cnt++, repeat for all other cows


int main(){
    vector<pair<int,int>> alpha(26, {-1, -1}); //record entry n exit
    freopen("circlecross.in", "r", stdin);
    str circle = "";
    int cnt = 0;
    cin >> circle;
    for(int i = 0; i < 52; i++){
        int alphaidx = circle.at(i) - 'A'; 
        if(alpha[alphaidx].first == -1) alpha[alphaidx].first = i;
        else alpha[alphaidx].second = i;
    }
    for(int p1idx = 0; p1idx < 26; p1idx++){
        for(int p2idx = 0; p2idx < 26; p2idx++){
            if(p1idx == p2idx) continue; //cannot be same cow
            pair<int, int> p1 = alpha[p1idx], p2 = alpha[p2idx];
            if(p1.first < p2.first && p2.first < p1.second && p1.second  < p2.second) cnt++;
        }
    }
    freopen("circlecross.out", "w", stdout);
    printf("%d", cnt);
    return 0;
}