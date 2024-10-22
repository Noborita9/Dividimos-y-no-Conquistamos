ll catalan(ll n) {
    if (n == 0) return 1;
    ll catalan_num = (fact[2 * n] * inv_fact[n] % MOD) * inv_fact[n + 1] % MOD;
    return catalan_num;
}
