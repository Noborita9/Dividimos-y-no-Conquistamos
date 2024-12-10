#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> compute_totients(ll n) {
    vector<ll> phi(n + 1);
    for (ll i = 0; i <= n; i++) {
        phi[i] = i;
    }

    for (ll i = 2; i <= n; i++) {
        if (phi[i] == i) { // i es primo
            for (ll j = i; j <= n; j += i) {
                phi[j] = phi[j] * (i - 1) / i;
            }
        }
    }

    return phi;
}