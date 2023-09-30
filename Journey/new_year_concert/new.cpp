#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2e5+10;
int n;
int a[N];
int f[N];

struct Something {
    int divisor;
    int Count;
};
deque<Something> something;

int p, q;
bool ok;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];

    f[0] = 0;
    for(int i = 1; i <= n; ++i) {
        deque<Something> something_else;
        something.push_front(Something {0, 1});
        for(const Something &alpha : something) {
            Something beta = {
                gcd(a[i], alpha.divisor),
                alpha.Count
            };
            if(something_else.size() == 0 || something_else.back().divisor != beta.divisor)
                something_else.push_back(beta);
            else if(something_else.back().divisor == beta.divisor)
                something_else.back().Count += beta.Count;
        }
        something = something_else;

        p = 0, q = 0;
        ok = true;

        for(const Something &alpha : something) {
            p = q + 1;
            q = q + alpha.Count;

            if(p <= alpha.divisor && alpha.divisor <= q) {
                ok = false;
                break;
            }
        }

        if(ok) f[i] = f[i-1];
        else {
            f[i] = f[i-1] + 1;
            something.clear();
        }
    }

    for(int i = 1; i <= n; ++i) cout << f[i] << ' ';
    cout << '\n';

    return 0;
}
