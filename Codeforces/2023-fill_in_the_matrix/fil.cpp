/*  Jan Zakrzewski
    https://codeforces.com/contest/1869/problem/C */
#include <bits/stdc++.h>
using namespace std;

int t;
int n, m, k;
int x;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        k = min(n+1, m);
        if(m == 1) cout << "0\n";
        else cout << k << '\n';
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(m == 1) x = 0;
                else if(j < k) x = (i % (k-1) + j) % k;
                else x = j;
                cout << x << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
