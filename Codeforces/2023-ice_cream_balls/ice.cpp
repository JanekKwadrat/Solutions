/*  Jan Zakrzewski
    https://codeforces.com/contest/1862/problem/D */

#include <bits/stdc++.h>
using namespace std;

int t;
int64_t n;

inline int64_t sth(int64_t k) {
    int64_t ans = k * (k - 1) / 2;
    return ans + min(max(int64_t(0), n - ans), k);
}

inline int64_t sth2(int64_t k) {
    int64_t ans = k * (k - 1) / 2;
    return k + min(max(int64_t(0), n - ans), k);
}

int64_t solve(int64_t n) {
    int64_t a = 0, b = 2'000'000'000; // sth(a) <= n < sth(b)
    while(b - a > 1) {
        int64_t mid = (a + b) / 2;
        if(sth(mid) > n) b = mid;
        else a = mid;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        cout << sth2(solve(n)) << '\n';
    }

    return 0;
}
