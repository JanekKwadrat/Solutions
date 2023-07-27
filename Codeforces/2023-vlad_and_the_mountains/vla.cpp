/*  Jan Zakrzewski
    https://codeforces.com/contest/1851/problem/G */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int t, n, m;
int h[N];
vector<int> neighbors[N];
pair<int, int> height_index[N]; // h[u], u

int q;
tuple<int, int, int, int> query[N]; // h[a] + e, a, b, itr
bool answer[N];

int Parent[N];
int Size[N];
inline int Find(int u) {
    while(u != Parent[u])
        u = Parent[u];
    return u;
}
inline void Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v) return;
    if(Size[u] < Size[v]) swap(u, v);
    Size[u] += Size[v];
    Parent[v] = u;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int u = 1; u <= n; ++u) {
            cin >> h[u];
            neighbors[u].clear();
            height_index[u] = make_pair(h[u], u);
        }
        sort(&height_index[1], &height_index[n]+1);
        for(int i = 1; i <= m; ++i) {
            int u, v;
            cin >> u >> v;
            neighbors[u].push_back(v);
            neighbors[v].push_back(u);
        }

        cin >> q;
        for(int i = 1; i <= q; ++i) {
            int a, b, e;
            cin >> a >> b >> e;
            query[i] = make_tuple(h[a] + e, a, b, i);
        }
        sort(&query[1], &query[q]+1);

        for(int u = 1; u <= n; ++u) {
            Parent[u] = u;
            Size[u] = 1;
        }

        int j = 1;
        for(int i = 1; i <= q; ++i) {
            int H = get<0>(query[i]);
            int a = get<1>(query[i]);
            int b = get<2>(query[i]);
            int itr = get<3>(query[i]);

            //cout << H << ' ' << a << ' ' << b << ' ' << itr << '\n';

            while(j <= n) {
                int u = height_index[j].second;
                if(h[u] > H) break;
                // add u
                for(int v : neighbors[u]) {
                    if(h[v] > h[u]) continue;
                    Union(u, v);
                }
                j++;
            }

            answer[itr] = Find(a) == Find(b);
        }

        for(int i = 1; i <= q; ++i) {
            if(answer[i]) cout << "yes\n";
            else cout << "no\n";
        }
    }

    return 0;
}