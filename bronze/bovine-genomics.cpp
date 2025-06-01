#include <bits/stdc++.h>
using namespace std;

void cnter(vector<bool> &cnt, char g)
{
    switch (g)
    {
    case 'A':
        cnt.at(0) = true;
        break;
    case 'T':
        cnt.at(1) = true;
        break;
    case 'C':
        cnt.at(2) = true;
        break;
    case 'G':
        cnt.at(3) = true;
        break;
    }
    return;
}

int main()
{
    freopen("cownomics.in", "r", stdin);
    int n = 0, m = 0, res = 0;
    scanf("%d %d", &n, &m);
    vector<string> spot(n), plain(n);
    for (int i = 0; i < n; i++)
        cin >> spot.at(i);
    for (int i = 0; i < n; i++)
        cin >> plain.at(i);

    for (int p = 0; p < m; p++)
    {
        vector<bool> spotcnt = {false, false, false, false}, plaincnt = {false, false, false, false};
        int cnt = 0;
        for (int c = 0; c < n; c++)
        {
            cnter(spotcnt, spot.at(c).at(p));
            cnter(plaincnt, plain.at(c).at(p));
        }

        for (int g = 0; g < 4; g++){
            bool sg = spotcnt.at(g), pg = plaincnt.at(g);
            if ( sg ^ pg || (!sg && !pg)) cnt++;
        }
        if (cnt == 4)
            res++;
    }
    freopen("cownomics.out", "w", stdout);
    printf("%d", res);
    return 0;
}