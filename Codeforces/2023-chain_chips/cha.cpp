/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1814/E */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
constexpr int D = 1 << 18; // D >= N
constexpr long long INF = 3e15;
int n, q;
int C[N];

struct Run {
    int a, b;
    long long yy, yn, ny, nn;
    Run operator*(Run oth) {
        if(!a && !b) return oth;
        if(!oth.a && !oth.b) return *this;

        Run ans = { a, oth.b, INF, INF, INF, INF };
        const int cost = C[b];

        ans.yy = min(ans.yy, yy + oth.yy);
        ans.yn = min(ans.yn, yy + oth.yn);
        ans.ny = min(ans.ny, ny + oth.yy);
        ans.nn = min(ans.nn, ny + oth.yn);

        ans.yy = min(ans.yy, yn + oth.ny + cost);
        ans.yn = min(ans.yn, yn + oth.nn + cost);
        ans.ny = min(ans.ny, nn + oth.ny + cost);
        ans.nn = min(ans.nn, nn + oth.nn + cost);

        //assert(ans.yy >= ans.yn && ans.yy >= ans.ny);
        //assert(ans.nn <= ans.yn && ans.nn <= ans.ny);
        
        return ans;
    }
} tree[2 * D] = {};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n-1; ++i) cin >> C[i];

    for(int i = 1; i <= n; ++i) tree[D + i] = { i, i, INF, 0, 0, 0 };
    for(int i = D-1; i >= 1; --i) tree[i] = tree[2 * i] * tree[2 * i + 1];

    cin >> q;
    while(q--) {
        int i, x;
        cin >> i >> x;
        C[i] = x;

        i += D;
        i /= 2;
        while(i >= 1) {
            tree[i] = tree[2 * i] * tree[2 * i + 1];
            i /= 2;
        }

        cout << tree[1].yy * 2 << '\n';
    }

    return 0;
}