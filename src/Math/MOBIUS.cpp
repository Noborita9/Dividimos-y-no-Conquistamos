#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


vector<ll> compute_mobius(ll n) {
    vector<ll> mu(n + 1, 1);
    vector<bool> is_prime(n + 1, true);

    for (ll i = 2; i <= n; i++) {
        if (is_prime[i]) { // i es un primo
            for (ll j = i; j <= n; j += i) {
                mu[j] *= -1; // Multiplicamos por -1 para cada primo
                is_prime[j] = false;
            }
            for (ll j = i * i; j <= n; j += i * i) {
                mu[j] = 0; // Si tiene un cuadrado de un primo, se pone en 0
            }
        }
    }

    return mu;
}


ll mobius(ll x) {
    ll count = 0;
    for (ll i = 2; i * i <= x; i++) {
        if (x % (i * i) == 0)
            return 0; 
        if (x % i == 0) {
            count++;
            x /= i;
        }
    }

    if (x > 1) count++;

    return (count % 2 == 0) ? 1 : -1;
}
