/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1826/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
constexpr int D = 2*N;
int t, n, d;
pair<int,int> a[2*D];
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        d = 1; while(!(d > n + 10)) d *= 2;
        for(int i = d; i <= 2*d; ++i) a[i] = { INT32_MIN, INT32_MIN };

        for(int i = 1; i <= n; ++i) {
            cin >> a[d + i].first;
            a[d + i].second = i;
        }
        
        for(int i = d-1; i >= 1; --i) a[i] = max(a[2*i], a[2*i+1]);

        auto First = [&](int i, pair<int, int> x) -> int {
            // returns the smallest i < j <= n such that a[d + j] > x or -1 if no such j exists
            // expects 1 <= i <= n or i = -1
            if(i == -1) return -1;
            int j = i + d;
            while(j > 1) {
                if(j % 2 == 0 && a[j+1] > x) {
                    j++;
                    while(j < d) {
                        if(a[2*j] > x) j = 2*j;
                        else j = 2*j + 1;
                    }
                    return j - d;
                }
                j /= 2;
            }
            return -1;
        };

        auto Last = [&](int i, pair<int, int> x) -> int {
            // returns the biggest 1 <= j < i such that a[d + j] > x or -1 if no such j exists
            // expects 1 <= i <= n or i = -1
            if(i == -1) return -1;
            int j = i + d;
            while(j > 1) {
                if(j % 2 == 1 && a[j-1] > x) {
                    j--;
                    while(j < d) {
                        if(a[2*j+1] > x) j = 2*j+1;
                        else j = 2*j;
                    }
                    return j - d;
                }
                j /= 2;
            }
            return -1;
        };

        ans = 0;
        for(int i = 1; i <= n; ++i) {
            int l, m, r;
            do {
                l = i;
                m = First(l, a[d + l]);
                r = First(m, a[d + l]);
                if(r == -1) continue;
                ans = max(ans, a[d + l].first + a[d + m].first + a[d + r].first - (r - l));
            } while(false);
            do {
                r = i;
                m = Last(r, a[d + r]);
                l = Last(m, a[d + r]);
                if(l == -1) continue;
                ans = max(ans, a[d + l].first + a[d + m].first + a[d + r].first - (r - l));
            } while(false);
            do {
                m = i;
                l = Last(m, a[d + m]);
                r = First(m, a[d + m]);
                if(l == -1 || r == -1) continue;
                ans = max(ans, a[d + l].first + a[d + m].first + a[d + r].first - (r - l));
            } while(false);
        }

        cout << ans << '\n';
    }

    return 0;
}