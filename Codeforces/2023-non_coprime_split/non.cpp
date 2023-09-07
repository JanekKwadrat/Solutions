/*  Jan Zakrzewski
    https://codeforces.com/contest/1872/problem/B */
#include <bits/stdc++.h>
using namespace std;

int constexpr X = 1e7 + 100;

int p[X];
int t, l, r;
int odp;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    for(int i = 2; i < X; ++i) p[i] = i;
    for(int i = 2; i*i < X; ++i) {
        if(p[i] != i) continue;
        for(int j = 2*i; j < X; j += i) p[j] = i;
    }

    cin >> t;
    while(t--) {
        cin >> l >> r;
        if(r <= 3) cout << "-1\n";
        else {
            odp = -1;
            if(p[r] != r) odp = r;
            else if(l < r && p[r-1] != r-1) odp = r-1;

            if(odp == -1) cout << "-1\n";
            else cout << p[odp] << ' ' << odp - p[odp] << '\n';
        }
    }

    return 0;
}
