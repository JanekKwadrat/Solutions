/*  Jan Zakrzewski
    https://codeforces.com/contest/1823/problem/F */

#include <bits/stdc++.h>
using namespace std;

int modInverse(int, int);

constexpr int32_t N = 2e5+10;
constexpr int32_t MOD = 998'244'353;
int32_t n;
int start, target;
vector<int32_t> neighbors[N];

int32_t parent[N];
vector<int32_t> children[N];

queue<int32_t> Queue;
bool visited[N] = {};

struct Q {
    int32_t p, q;
    inline Q(int32_t pp = 0, int32_t qq = 1) {
        p = pp, q = qq;
    }
    inline Q operator+(const Q& oth) const {
        return Q(
            ((int64_t) p * oth.q + (int64_t) oth.p * q) % MOD,
            (int64_t) q * oth.q % MOD
        );
    }
    inline Q operator*(const Q& oth) const {
        return Q(
            (int64_t) p * oth.p % MOD,
            (int64_t) q * oth.q % MOD
        );
    }
    inline Q inverse() const {
        return Q(q, p);
    }
    inline int32_t extract() const {
        // Hope it works ???
        
        return (int64_t) p * modInverse(q, MOD) % MOD;
        
        for(int32_t x = 0; x < MOD; ++x) {
            if((int64_t) x * q % MOD == p)
                return x;
        }
    }
} ans[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> n >> start >> target;
    for(int i = 1; i <= n-1; ++i) {
        int u, v;
        cin >> u >> v;
        neighbors[u].push_back(v);
        neighbors[v].push_back(u);
    }

    Queue.push(start);
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
    for(int u = 1; u <= n; ++u) visited[u] = false;

    {
        int u = target;
        ans[target] = Q(0, 1);
        while(u != start) {
            visited[u] = true;
            int v = parent[u];

            ans[v] = ans[u] * Q(neighbors[v].size(), neighbors[u].size()) + Q(neighbors[v].size(), 1);

            Queue.push(v);
            u = v;
        }
    }
    
    while(Queue.size() > 0) {
        int u = Queue.front();
        Queue.pop();

        for(int v : children[u]) {
            if(visited[v]) continue;

            ans[v] = ans[u] * Q(neighbors[v].size(), neighbors[u].size());

            Queue.push(v);
        }
    }    
    ans[target] = Q(1, 1);

    //for(int u = 1; u <= n; ++u) cout << ans[u].p << ' ' << ans[u].q << '\n';;
    for(int u = 1; u <= n; ++u) cout << ans[u].extract() << ' ';
    cout << '\n';

    return 0;
}


// From: https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/
int modInverse(int A, int M)
{
    int m0 = M;
    int y = 0, x = 1;
 
    if (M == 1)
        return 0;
 
    while (A > 1) {
        // q is quotient
        int q = A / M;
        int t = M;
 
        // m is remainder now, process same as
        // Euclid's algo
        M = A % M, A = t;
        t = y;
 
        // Update y and x
        y = x - q * y;
        x = t;
    }
 
    // Make x positive
    if (x < 0)
        x += m0;
 
    return x;
}