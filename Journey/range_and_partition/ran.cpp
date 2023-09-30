#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t;
int n, k;
int a[N];

int b[N];
int atleast; // How many a[i] do we need at least to be in the range [x, y]?
int x, y;

bool Next;
int l, r;
int inside, outside;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        for(int i = 1; i <= n; ++i) b[i] = a[i];
        sort(&b[1], &b[n]+1);

        atleast = k + (n - k + 1) / 2;
        x = 0, y = 0;
        for(int i = 1; i + atleast - 1 <= n; ++i) {
            int p = b[i], q = b[i + atleast - 1];
            if(x == 0 && y == 0 || q - p < y - x) {
                x = p;
                y = q;
            }
        }

        cout << x << ' ' << y << '\n';
        Next = true;
        for(int i = 1; i <= n; ++i) {
            if(Next) {
                l = i, r = i;
                inside = 0;
                outside = 0;
                Next = false;
            } else r++;

            if(x <= a[i] && a[i] <= y) inside++;
            else outside++;

            if(inside > outside) {
                Next = true;
                k--;
                if(k == 0) {
                    cout << l << ' ' << n << '\n';
                    break;
                } else cout << l << ' ' << r << '\n';
            }
        }
    }

    return 0;
}
