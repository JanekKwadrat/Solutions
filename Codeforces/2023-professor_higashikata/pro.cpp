/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1847/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
constexpr int D = 1 << 18; // D >= N + 1
constexpr int X = 1e9;

int n, m, q;
char s[N];
int tree[2 * D];
pair<long long, int> sorted[N];
int translate[N];

int sth[N];
int k, sum, zeros;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> q;
    cin >> s + 1;

    for(int i = 1; i < 2 * D; ++i) tree[i] = X;
    for(int i = 1; i <= m; ++i) {
        int l, r;
        cin >> l >> r;
        l += D;
        r += D;
        tree[l] = min(tree[l], i);
        tree[r] = min(tree[r], i);
        while(l / 2 != r / 2) {
            if(l % 2 == 0) tree[l+1] = min(tree[l+1], i);
            if(r % 2 == 1) tree[r-1] = min(tree[r-1], i);
            l /= 2;
            r /= 2;
        }
    }
    for(int j = 1; j < D; ++j) {
        tree[2*j  ] = min(tree[2*j  ], tree[j]);
        tree[2*j+1] = min(tree[2*j+1], tree[j]);
    }

    k = 0;
    for(int i = 1; i <= n; ++i) {
        if(tree[i+D] < X) k++;
        sorted[i].first = (long long) X * tree[i+D] + i;
        sorted[i].second = i;
    }
    sort(&sorted[1], &sorted[n]+1);

    sum = 0;
    for(int i = 1; i <= n; ++i) translate[sorted[i].second] = i;

    for(int i = 1; i <= n; ++i) {
        int x = translate[i];
        sth[x] = s[i] - '0';
        sum += sth[x];
    }
    zeros = 0;
    for(int x = 1; x <= sum && x <= k; ++x) {
        if(sth[x] == 0) zeros++;
    }


    //for(int i = 1; i <= n; ++i) cout << sorted[i].second << ' '; cout << '\n';
    //for(int i = 1; i <= n; ++i) cout << sth[i] << ' '; cout << '\n';
    //cout << sum << ' ' << zeros << ' ' << k << '\n';

    while(q--) {
        int x;
        cin >> x;
        x = translate[x];
        sth[x] = 1 - sth[x];

        if(x <= sum && x <= k) {
            if(sth[x]) zeros--;
            else zeros++;
        }

        if(sth[x]) {
            sum++;
            if(sum <= k) if(!sth[sum]) zeros++;
        } else {
            if(sum <= k) if(!sth[sum]) zeros--;
            sum--;
        }
        
        //for(int i = 1; i <= n; ++i) cout << sorted[i].second << ' '; cout << '\n';
        //for(int i = 1; i <= n; ++i) cout << sth[i] << ' '; cout << '\n';
        //cout << sum << ' ' << zeros << ' ' << k << '\n';

        cout << zeros << '\n';
    }

    return 0;
}

/*
2 2 3
00
1 1
2 2
2 
1 
2
*/