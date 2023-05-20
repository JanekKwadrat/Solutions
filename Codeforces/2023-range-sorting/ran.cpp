/*  Jan Zakrzewski
    https://codeforces.com/contest/1828/problem/D2 */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5+10;
constexpr int D = 1 << 19; // D > N + 100
int t, n, d;
int a[2*D];
int b[2*D];
long long ans = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        d = 32;
        while(! (d > n + 100)) d *= 2;

        for(int i = d; i < 2*d; ++i) a[i] = INT32_MIN;
        a[d] = INT32_MAX;
        for(int i = d; i < 2*d; ++i) b[i] = INT32_MAX;
        b[d+n+1] = INT32_MIN;
        for(int i = 1; i <= n; ++i) cin >> a[i + d];
        for(int i = 1; i <= n; ++i) b[i + d] = a[i + d];
        
        for(int i = d-1; i >= 1; --i) a[i] = max(a[2*i], a[2*i+1]); 
        for(int i = d-1; i >= 1; --i) b[i] = min(b[2*i], b[2*i+1]); 

        ans = (long long) (n - 1) * n * (n + 1) / 6;       
        for(int i = 1; i <= n; ++i) {
            // find the smallest j > i such that a[j+d] > a[i+d]
            int j = i + d;
            while(j > 1) {
                if(j % 2 == 0 && a[j+1] > a[i+d]) {
                    j++;
                    while(j < d) {
                        if(a[2*j] > a[i+d]) j = 2*j;
                        else j = 2*j+1;
                    }
                    break;
                }
                j /= 2;
            }
            j -= d;
            if(! (j > i && j <= n && a[j+d] > a[i+d])) continue;

            //find the biggest jj >= j such that a[x+d] > a[i+d] for all j <= x <= jj
            int jj = j + d;
            while(jj > 1) {
                if(jj % 2 == 0 && b[jj+1] < b[i+d]) {
                    jj++;
                    while(jj < d) {
                        if(b[2*jj] < b[i+d]) jj = 2*jj;
                        else jj = 2*jj+1;
                    }
                    break;
                }
                jj /= 2;
            }
            jj -= d;
            jj--;

            //find the smallest ii <= i such that a[x+d] <= a[i+d] for all ii <= x <= i
            int ii = i + d;
            while(ii > 1) {
                if(ii % 2 == 1 && a[ii-1] > a[i+d]) {
                    ii--;
                    while(ii < d) {
                        if(a[2*ii+1] > a[i+d]) ii = 2*ii + 1;
                        else ii = 2*ii;
                    }
                    break;
                }
                ii /= 2;
            }
            ii -= d;
            ii++;

            //answer computation
            ans -= (long long) (i - ii + 1) * (jj - j + 1);
        }

        cout << ans << '\n';
    }

    return 0;
}
