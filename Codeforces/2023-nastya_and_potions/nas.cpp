/*  Jan Zakrzewski
    https://codeforces.com/contest/1851/problem/E */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
constexpr int INF = 1e9+100;
int t, n, k;
int c[N];
int m[N];

int alt[N];
vector<int> way[N];

queue<int> Queue;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> k;
        for(int u = 1; u <= n; ++u) cin >> c[u];
        for(int i = 1; i <= k; ++i) {
            int p;
            cin >> p;
            c[p] = 0;
        }
        for(int u = 1; u <= n; ++u) way[u].clear();
        for(int u = 1; u <= n; ++u) {
            cin >> m[u];
            if(m[u] == 0) alt[u] = INF;
            else alt[u] = 0;
            for(int i = 1; i <= m[u]; ++i) {
                int v;
                cin >> v;
                way[v].push_back(u);
            }
        }

        for(int u = 1; u <= n; ++u) {
            if(m[u] == 0) {
                Queue.push(u);
            }
        }

        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();

            c[u] = min(c[u], alt[u]);
            for(int v : way[u]) {
                alt[v] += c[u];
                alt[v] = min(alt[v], INF);
                m[v]--;
                if(m[v] == 0) Queue.push(v);
            }
        }

        for(int u = 1; u <= n; ++u)
            cout << c[u] << ' ';
        cout << '\n';
    }

    return 0;
}