/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1814/D */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3000+10;
constexpr int K = 1500+10;
int t, n, k;
int x[N], a[N];

long long y[N];
int d;
int ok[2*K];

vector<pair<long long,bool>> sorted;
vector<pair<long long,bool>> good;

int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    // I had to deal with MLE somehow.
    sorted.reserve(5'000'000);
    good.reserve(5'000'000);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        d = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> x[i];
            if(x[i] > k+1) d++;
        }
        for(int i = 1; i <= n; ++i) cin >> a[i];

        sorted.clear();
        for(int i = 1; i <= n; ++i) {
            y[i] = (long long) x[i] * a[i];
            for(int j = 0; j <= 2*k; ++j) ok[j] = 0;
            for(int j = 1; j <= n; ++j) {
                if(x[j] <= k+1) continue;
                long long z = (y[i] + k) / x[j] * x[j];
                while(z > 0 && z >= y[i] - k) {
                    ok[z - (y[i] - k)]++;
                    z -= x[j];
                }
            }
            int s = 0;
            for(int j = 0; j <= k; ++j) s += ok[j];
            for(int j = 0;true;) {
                sorted.push_back(make_pair(y[i]-k + j, s >= d));
                if(j >= k) break;
                s -= ok[j];
                j++;
                s += ok[j+k];
            }
        }
        sort(sorted.begin(), sorted.end());

        good.clear();
        for(auto elm : sorted) {
            if(good.size() == 0 || good.back().first != elm.first) good.push_back(elm);
            else good.back().second = good.back().second && elm.second;
        }

        sort(&y[1], &y[n]+1);

        ans = 0;
        int i = 1, j = 0;
        for(auto elm : good) {
            if(!elm.second) continue;
            long long u = elm.first, v = elm.first + k;
            if(u < 1) continue;
            while(j+1 <= n && y[j+1] <= v) j++;
            while(i <= j && y[i] < u) i++;
            ans = max(ans, j - i + 1);
        }

        ans = n - ans;
        cout << ans << '\n';
    }

    return 0;
}