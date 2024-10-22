// Función para precalcular los factoriales y sus inversos modulares
vector<ll> fact, inv_fact;
void precompute_factorials(ll n, ll mod) {
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = inv_fact[0] = 1;
    for (ll i = 1; i <= n; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv_fact[n] = mod_inverse(fact[n], mod);
    for (ll i = n - 1; i >= 1; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
    }
}

// Función para calcular C(n, k) % mod
ll binomial_coefficient(ll n, ll k, ll mod) {
    if (k > n) return 0;
    return (fact[n] * inv_fact[k] % mod) * inv_fact[n - k] % mod;
}