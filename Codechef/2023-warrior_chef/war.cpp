/*  Jan Zakrzewski
    https://www.codechef.com/START101D/problems/WARRIORCHEF */

#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1e5+10;
int t;
int n, h;
int a[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> h;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(&a[1], &a[n]+1);

        ans = 0;
        for(int i = n; i >= 1; --i) {
            if(h - a[i] >= 1) h -= a[i];
            else {
                ans = a[i];
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
