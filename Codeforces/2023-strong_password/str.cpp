/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1845/C */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3e5+20;
int t, n, m;
char s[N];
char l[N], r[N];
int pierwsza[N][10];
int ptr, Next;
bool ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> s+1;
        n = strlen(s+1);
        cin >> m;
        cin >> l+1 >> r+1;

        for(int i = 0; i < 10; ++i) pierwsza[n][i] = n+1;
        pierwsza[n][s[n]-'0'] = n;

        for(int i = n-1; i >= 1; --i) {
            for(int j = 0; j < 10; ++j) {
                pierwsza[i][j] = pierwsza[i+1][j];
            }
            pierwsza[i][s[i]-'0'] = i;
        }

        ok = true;
        ptr = 0;
        for(int i = 1; i <= m; ++i) {
            if(ptr+1 > n) { ok = false; break; }
            Next = 0;
            for(char c = l[i]; c <= r[i]; ++c) {
                Next = max(Next, pierwsza[ptr+1][c-'0']);
            }
            ptr = Next;
            if(ptr > n) { ok = false; break; }
            //cout << ptr << ' ';
        }
        //cout << '\n';
        //cout << ptr << " " << n << "\n";
        //if(ptr <= n) ok = true;

        if(!ok) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}