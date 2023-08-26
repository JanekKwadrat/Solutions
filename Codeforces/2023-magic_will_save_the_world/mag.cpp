/*  Jan Zakrzewski
    https://codeforces.com/contest/1862/problem/F */

#include <bits/stdc++.h>
using namespace std;

int constexpr N = 1e4 + 10;
int constexpr Y = 1e4;

int t;
int w, f;
int n, s[N];

class abba {
    int n, cap;
    uint64_t* arr;
public:
    abba(int nn = 0) {
        assert(nn >= 0);
        n = nn;
        cap = (n + 63) / 64;
        arr = new uint64_t[cap];
        for(int i = 0; i < cap; ++i) arr[i] = 0;
    }
    ~abba() {
        delete[] arr;
    }
    void resize(int nn) {
        assert(nn >= 0);
        delete[] arr;
        n = nn;
        cap = (n + 63) / 64;
        arr = new uint64_t[cap];
        for(int i = 0; i < cap; ++i) arr[i] = 0;
    }
    void magic(int ile) {
        assert(ile >= 0);
        for(int i = cap-1; i >= 0; --i) {
            int j = i - ile / 64;
            int s = ile % 64;
            if(j   >= 0)          arr[i] |= arr[j]   << s;
            if(j-1 >= 0 && s > 0) arr[i] |= arr[j-1] >> (64 - s);
        }
    }
    bool get(int i) {
        assert(i >= 0 && i < n);
        return (arr[i / 64] >> i % 64) & 0x1;
    }
    void set(int i, bool val) {
        assert(i >= 0 && i < n);
        arr[i / 64] &= ~((uint64_t(1)     << i % 64));
        arr[i / 64] ^=   (uint64_t(!!val) << i % 64);
    }
};

int X;
long long sum;
abba ok;
long long ww, ff;
long long ans, another;
long long w_ile, f_ile;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> w >> f;
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> s[i];

        X = Y * n + 1;
        sum = 0;
        ok.resize(X);
        ok.set(0, true);

        for(int i = 1; i <= n; ++i) {
            ok.magic(s[i]);
            sum += s[i];
        }

        // for(int i = 0; i < X; ++i) cout << ok.get(i) << ' '; cout << '\n';

        ans = INT64_MAX;
        for(int i = 0; i < X; ++i) {
            ww = i;
            ff = sum - i;
            if(!ok.get(i)) continue;
            if(ww < 0 || ff < 0) continue;

            // cout << ww << ' ' << ff << '\n';

            w_ile = (ww + w - 1) / w;
            f_ile = (ff + f - 1) / f;
            another = max(w_ile, f_ile);

            ans = min(ans, another);
        }

        cout << ans << '\n';
    }

    return 0;
}
