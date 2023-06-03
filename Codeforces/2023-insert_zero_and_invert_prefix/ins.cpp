/*  Jan Zakrzewski
    https://codeforces.com/contest/1839/problem/C */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5+10;
int t, n;
int a[N];
vector<int> p;
vector<int> q;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];

        p.clear();
        q.clear();
        for(int i = 2; i <= n; ++i) {
            if(a[i] != a[i-1]) q.push_back(i-1);
        }
        while(p.size() + q.size() < n) p.push_back(0);

        if(a[n] == 1) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int x : p) cout << x << ' ';
            for(int x : q) cout << x << ' ';
            cout << '\n';
        }
    }

    return 0;
}