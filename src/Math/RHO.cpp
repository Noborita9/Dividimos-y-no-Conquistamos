ll mul(ll a, ll b, ll mod) {
    return (__int128)a * b % mod;
}

ll power(ll a, ll b, ll mod) {
    ll res = 1;
    while (b) {
        if (b & 1) res = mul(res, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

bool isPrime(ll n) {
    if (n < 2) return false;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19, 23}) {
        if (n % p == 0) return n == p;
    }
    ll d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, ++s;
    for (ll a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (a % n == 0) continue;
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool ok = false;
        for (int i = 0; i < s; ++i) {
            x = mul(x, x, n);
            if (x == n - 1) { ok = true; break; }
        }
        if (!ok) return false;
    }
    return true;
}

ll rho(ll n) {
    if (n % 2 == 0) return 2;
    while (true) {
        ll c = rand() % (n - 1) + 1;
        ll x = 2, y = 2, d = 1;
        while (d == 1) {
            x = (mul(x, x, n) + c) % n;
            y = (mul(y, y, n) + c) % n;
            y = (mul(y, y, n) + c) % n;
            d = std::gcd((x > y ? x - y : y - x), n);
        }
        if (d != n) return d;
    }
}

void fact(ll n, std::map<ll, int>& f) {
    if (n == 1) return;
    if (isPrime(n)) { f[n]++; return; }
    ll d = rho(n);
    if (d == n) { 
        f[n]++;
        return;
    }
    fact(d, f);
    fact(n / d, f);
}
