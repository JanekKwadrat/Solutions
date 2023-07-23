/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1846/E2 */

#include <bits/stdc++.h>
using namespace std;

constexpr uint64_t INF = UINT64_MAX;

inline uint64_t mul(uint64_t a, uint64_t b) {
    if(a == 0) return 0;
    else if(b > INF / a) return INF;
    else return a * b;
}

inline uint64_t add(uint64_t a, uint64_t b) {
    if(b > INF - a) return INF;
    else return a + b;
}


uint64_t snowflake(uint32_t a, uint32_t n) {
    if(a == 0) return 0;
    if(a == 1) return n;
    uint64_t ans = 0;
    while(n--) {
        ans = mul(ans, a);
        ans = add(ans, 1);
        if(ans >= INF) return INF;
    }
    return ans;
}

int t;
uint64_t x;
bool ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> x;
        ok = false;
        for(uint32_t n = 3; n <= 64; ++n) {
            // snowflake(l, n) <= x < snowflake(r, n) holds at all times
            uint64_t l = 0, r = INF;
            while(r - l > 1) {
                uint64_t m = (l + r) / 2;
                if(x >= snowflake(m, n)) l = m;
                else r = m;
            }
            
            if(l > 1 && snowflake(l, n) == x)
                ok = true;
        }

        if(ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}