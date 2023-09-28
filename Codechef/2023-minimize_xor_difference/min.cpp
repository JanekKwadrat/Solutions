/*  Jan Zakrzewski
    https://www.codechef.com/START101D/problems/XORDIF */

#include <bits/stdc++.h>
using namespace std;

int constexpr K = 30;
int t;
int a, b;
bool go;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b;
        ans = 0;

        a ^= b;
        ans ^= b;
        b = 0;

        for(int k = 29; k >= 0; --k) {
            if(a & (1 << k)) {
                ans ^= (1 << k);
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
