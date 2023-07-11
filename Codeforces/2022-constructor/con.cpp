/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1748/D */

#include <bits/stdc++.h>
using namespace std;

int t;
uint64_t a, b, d;
uint64_t x, q;
uint64_t Alpha, Beta;
int licznik;
bool ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> a >> b >> d;
        
        licznik = 0;
        while(d % 2 == 0) {
            d /= 2;
            licznik++;
        }
        q = (d + 1) / 2;
        while(licznik) {
            licznik--;
            d *= 2;
        }

        Beta = (a | b);
        Alpha = (d * 0x40000000ull - Beta) % d;
        for(int i = 30; i--;) Alpha = (Alpha * q) % d;

        x = Alpha * 0x40000000ull + Beta;
        ok = (x | a) % d == 0 && (x | b) % d == 0;
        
        if(!ok) cout << "-1\n";
        else cout << x << '\n';
    }

    return 0;
}