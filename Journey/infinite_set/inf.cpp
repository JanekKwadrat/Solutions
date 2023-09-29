#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int constexpr M = 1e9+7;
int n, p;
int a[N];
unordered_set<int> G;
int fibsum[N];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> p;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
        G.insert(a[i]);
    }

    for(int i = 1; i <= n; ++i) {
        int x = a[i];
        while(true) {
            if(x == 0) break;
            else if(x % 4 == 0) x /= 4;
            else if(x % 2 == 1) x /= 2;
            else break;
            if(G.count(x)) G.erase(a[i]);
        }
    }

    fibsum[0] = 1;
    fibsum[1] = 1;
    for(int i = 2; i <= p; ++i) fibsum[i] = (fibsum[i-1] + fibsum[i-2]) % M;
    for(int i = 1; i <= p; ++i) fibsum[i] = (fibsum[i] + fibsum[i-1]) % M;

    ans = 0;
    for(int g : G) {
        int l = 0;
        while(g > 0) {
            l++;
            g /= 2;
        }
        l = p - l;
        if(l >= 0) ans = (ans + fibsum[l]) % M;
    }

    cout << ans << '\n';

    return 0;
}
