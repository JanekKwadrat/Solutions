/*  Jan Zakrzewski
    https://codeforces.com/problemset/problem/1848/E */

#include <bits/stdc++.h>
using namespace std;

int modInverse(int, int);

constexpr int X = 1e6 + 20;

int x, q, M;

struct Sth {
    int p, q, c;

    Sth() {
        p = 1, q = 1, c = 0;
    }

    int gimme() {
        assert(c >= 0);
        if(c > 0) return 0;

        p = (long long) p * modInverse(q, M) % M;
        q = 1;
        return p;
    }

    int multiply(int x) {
        while(x % M == 0) {
            x /= M;
            c++;
        } 
        p = (long long) p * x % M;
    }

    int divide(int x) {
        while(x % M == 0) {
            x /= M;
            c--;
        } 
        q = (long long) q * x % M;
    }
} answer;
int fact[X] = {};
vector<int> primes[X];



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> x >> q >> M;

    while(x % 2 == 0) x /= 2;
    for(int i = 3; i < X; i += 2) {
        while(x % i == 0) {
            fact[i]++;
            x /= i;
        }
        answer.multiply(fact[i] + 1);
    }

    if(x > 1) answer.multiply(2);

    for(int i = 3; i < X; i += 2) {
        if(primes[i].size() > 0) continue;
        for(int j = i; j < X; j += i) {
            int jj = j;
            while(jj % i == 0) {
                jj /= i;
                primes[j].push_back(i);
            }
        }
    }

    while(q--) {
        int xi;
        cin >> xi;

        for(int p : primes[xi]) {
            answer.divide(fact[p] + 1);
            fact[p]++;
            answer.multiply(fact[p] + 1);
        }

        cout << answer.gimme() << '\n';
    }

    return 0;
}


// From: https://www.geeksforgeeks.org/multiplicative-inverse-under-modulo-m/

// Returns modulo inverse of a with respect
// to m using extended Euclid Algorithm
// Assumption: a and m are coprimes, i.e.,
// gcd(A, M) = 1
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