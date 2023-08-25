/*  Jan Zakrzewski
    https://codeforces.com/contest/1862/problem/A */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 30;
int t, n, m;
char s[N];
bool sth[N][256];
int ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int i = 1; i <= m; ++i) {
            for(int j = 0; j < 256; ++j) {
                sth[i][j] = false;
            }
        }
        for(int i = 1; i <= n; ++i) {
            cin >> s+1;
            for(int j = 1; j <= m; ++j) {
                sth[j][s[j]] = true;
            }
        }

        ok = 0;
        for(int j = 1; j <= m; ++j) {
            switch(ok) {
                case 0: if(sth[j]['v']) ok++; break;
                case 1: if(sth[j]['i']) ok++; break;
                case 2: if(sth[j]['k']) ok++; break;
                case 3: if(sth[j]['a']) ok++; break;
            }
        }

        if(ok >= 4) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
