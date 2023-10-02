#include <bits/stdc++.h>
using namespace std;

int n;
int a, b;
int mid, k, c;
int sth;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n;

    a = 1, b = n;
    while(b - a > 1) {
        mid = (a + b) / 2;
        k = 1 + mid / n;
        c = n * k - mid;

        a += c;
        mid += c;
        b += c;

        cout << "+ " << c << '\n';
        cout.flush();
        cin >> sth;

        if(sth >= k) a = mid;
        else b = mid;
    }

    cout << "! " << a << '\n';

    return 0;
}
