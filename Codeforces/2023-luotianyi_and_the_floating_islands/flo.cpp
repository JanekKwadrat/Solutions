/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1824/B2 */

#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
constexpr int M = 1e9+7;
int n, k;
vector<int> neighbors[N];

int root;
vector<int> children[N];
int parent[N];

queue<int> Queue;
bool visited[N];
int subtree_size[N];

int ans;

int factorial[N]; // factorial[i] = i ! % M
int computeModularInverse(int a, int m) {
    int m0 = m;
    int y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        int q = a / m;
        int t = m;

        m = a % m, a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}
inline int binomial(int a, int b) {
    return (long long) factorial[a] * computeModularInverse((long long) factorial[b] * factorial[a-b] % M, M) % M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> k;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    if(k % 2 == 1) {
        cout << "1\n";
        return 0;
    }

    factorial[0] = 1;
    for(int i = 1; i <= n; ++i) factorial[i] = (long long) factorial[i-1] * i % M;

    for(int u = 1; u <= n; ++u) visited[u] = false;
    root = 1;
    Queue.push(root);
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();
        visited[u] = true;
        for(int v : neighbors[u]) {
            if(visited[v]) parent[u] = v;
            else {
                children[u].push_back(v);
                Queue.push(v);
            }
        }
    }    

    for(int u = 1; u <= n; ++u) subtree_size[u] = -1;
    function<int(int)> ComputeSubtreeSize = [&](int u) -> int {
        if(subtree_size[u] == -1) {
            subtree_size[u] = 1;
            for(int v : children[u]) subtree_size[u] += ComputeSubtreeSize(v);
        }
        return subtree_size[u];
    };
    for(int u = 1; u <= n; ++u) ComputeSubtreeSize(u);

    ans = 0;
    for(int u = 1; u <= n; ++u) {
        int a = subtree_size[u];
        int b = n - a;

        if(a < k / 2 || b < k / 2) continue;
        ans += (long long) binomial(a, k / 2) * binomial(b, k / 2) % M;
        ans %= M;
    }

    ans = (long long) ans * computeModularInverse(binomial(n, k), M) % M;
    ans = (ans + 1) % M;

    cout << ans << '\n';

    return 0;
}