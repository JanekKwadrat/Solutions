/*  Jan Zakrzewski
    https://codeforces.com/contest/1872/problem/D */
#include <bits/stdc++.h>
using namespace std;

int t;
int64_t n, x, y;
int64_t true_xs;
int64_t true_ys;
int64_t answer;

inline int64_t sum(int64_t a, int64_t b) {
    int64_t A = a * (a - 1) / 2;
    int64_t B = b * (b + 1) / 2;
    return B - A;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n >> x >> y;
        true_xs = n / x - n / lcm(x, y);
        true_ys = n / y - n / lcm(x, y);

        answer = 0;
        answer += sum(n - true_xs + 1, n);
        answer -= sum(1, true_ys);

        cout << answer << '\n';
    }

    return 0;
}
