/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1824/A */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
int t, n, m;
int l, r, A;
int seat[N];
int prefix[N];
int suffix[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        l = 0, r = 0, A = 0;
        for(int x = 1; x <= m; ++x) seat[x] = 0;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            if(x == -1) l++;
            else if(x == -2) r++;
            else if(!seat[x]) {
                seat[x] = 1;
                A++;
            }
        }

        prefix[1] = 0;
        for(int x = 2; x <= m; ++x) prefix[x] = prefix[x-1] + seat[x-1];
        suffix[m] = 0;
        for(int x = m-1; x >= 1; --x) suffix[x] = suffix[x+1] + seat[x+1];

        ans = 0;
        for(int x = 1; x <= m; ++x) {
            if(!seat[x]) continue;
            ans = max(ans, 
                min(prefix[x] + l, x - 1) +
                min(suffix[x] + r, m - x) +
                1
            );
        }
        ans = max(ans, min(A + r, m));
        ans = max(ans, min(A + l, m));

        cout << ans << '\n';
    }

    return 0;
}