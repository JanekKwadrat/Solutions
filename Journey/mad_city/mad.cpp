#include <bits/stdc++.h>
using namespace std;

int constexpr N = 2e5+10;
int t;
int n, a, b;
vector<int> neighbors[N];

int spot;
bool visited[N];
stack<pair<int,int>> Stack;

int dist[N];
queue<int> Queue;

bool ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        for(int u = 1; u <= n; ++u) neighbors[u].clear();
        for(int i = 1; i <= n; ++i) {
            int u, v;
            cin >> u >> v;
            neighbors[u].push_back(v);
            neighbors[v].push_back(u);
        }

        for(int u = 1; u <= n; ++u) visited[u] = false;
        visited[b] = true;
        for(int u : neighbors[b]) Stack.push(make_pair(b, u));

        while(Stack.size() > 0) {
            int u = Stack.top().first;
            int v = Stack.top().second;
            Stack.pop();
            if(visited[v]) {
                spot = v;
                break;
            } else {
                visited[v] = true;
                for(int w : neighbors[v]) {
                    if(w != u) Stack.push(make_pair(v, w));
                }
            }
        }
        while(Stack.size() > 0) Stack.pop();

        for(int u = 1; u <= n; ++u) visited[u] = false;
        dist[spot] = 0;
        visited[spot] = true;
        Queue.push(spot);

        while(Queue.size() > 0) {
            int u = Queue.front();
            Queue.pop();
            for(int v : neighbors[u]) {
                if(!visited[v]) {
                    dist[v] = dist[u] + 1;
                    visited[v] = true;
                    Queue.push(v);
                }
            }
        }

        ans = dist[a] > dist[b];
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
