/*  Jan Zakrzewski
    https://www.codechef.com/START101D/problems/LPC */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+20;
int t;
int n, m;
char s[N];
char k[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        cin >> s;
        cin >> k;

        ans = INT32_MAX;
        for(int i = 0; i + m <= n; ++i) {
            int ans1 = 0;
            for(int j = 0; j < m; ++j) {
                int sth = s[i+j] - k[j];
                sth = (sth + 100) % 10;
                if(sth > 5) sth = 10 - sth;

                ans1 += sth;
            }

            if(ans1 < ans) ans = ans1;
        }

        cout << ans << '\n';
    }

    return 0;
}
