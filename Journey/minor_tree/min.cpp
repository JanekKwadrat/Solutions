#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int constexpr K = 30;
int t, n, m;
vector<pair<int,int>> neighbors[N];

unsigned mask;
unsigned candidate;
bool okay;

bool visited[N];
queue<int> Queue;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> m;
        for(int u = 1; u <= n; ++u) neighbors[u].clear();
        for(int i = 1; i <= m; ++i) {
            int u, v, w;
            cin >> u >> v >> w;
            neighbors[u].push_back({v,w});
            neighbors[v].push_back({u,w});
        }

        mask = 0;
        for(int k = K-1; k >= 0; --k) {
            candidate = mask | (1 << k);

            for(int u = 1; u <= n; ++u) visited[u] = false;
            while(Queue.size() > 0) Queue.pop();

            Queue.push(1);
            visited[1] = true;
            while(Queue.size() > 0) {
                int u = Queue.front();
                Queue.pop();
                for(pair<int,int> elm : neighbors[u]) {
                    int v = elm.first;
                    int w = elm.second;
                    if(visited[v]) continue;
                    if((candidate & w) != 0) continue;
                    Queue.push(v);
                    visited[v] = true;
                }
            }

            okay = true;
            for(int u = 1; u <= n; ++u) okay = okay && visited[u];

            if(okay) mask = candidate;
        }

        cout << (~mask & ((1 << K) - 1)) << '\n';
    }

    return 0;
}
