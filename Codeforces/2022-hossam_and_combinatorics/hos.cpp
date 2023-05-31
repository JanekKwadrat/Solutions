/*  Jan Zakrzewski
    https://codeforces.com/contest/1771/problem/A */

#include <bits/stdc++.h>
using namespace std;

int t, n, a;
int minimum, minimum_count;
int maximum, maximum_count;
long long ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        minimum = INT32_MAX, minimum_count = 0;
        maximum = INT32_MIN, maximum_count = 0;
        for(int i = 1; i <= n; ++i) {
            cin >> a;
            if(a == minimum) minimum_count++;
            else if(a < minimum) {
                minimum = a;
                minimum_count = 1;
            }
            if(a == maximum) maximum_count++;
            else if(a > maximum) {
                maximum = a;
                maximum_count = 1;
            }
        }

        if(minimum < maximum) ans = (long long) minimum_count * maximum_count * 2;
        else ans = (long long)  minimum_count * (minimum_count - 1);

        cout << ans << '\n';
    }

    return 0;
}