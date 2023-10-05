#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int constexpr M = 998244353;
int t, n;
char s[N];
int Count, Supercount;
int ops, ans;

int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> s+1;
        n = strlen(s+1);
        s[0] = '2';

        Count = 1, Supercount = 0;
        ops = n, ans = 1;
        for(int i = 1; i <= n; ++i) {
            if(s[i] == s[i-1]) {
                Count++;
                Supercount++;
                ans = (long long) ans * Supercount % M;
            } else {
                ans = (long long) ans * Count % M;
                Count = 1;
                ops--;
            }
        }
        ans = (long long) ans * Count % M;

        cout << ops << ' ' << ans << '\n';
    }

    return 0;
}
