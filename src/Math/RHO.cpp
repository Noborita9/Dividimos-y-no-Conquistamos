//RECOMENDADO USAR UNSIGNED LONG LONG
ll mulmod(ll a, ll b, ll m) { return ll(__int128(a) * b % m); }

ll expmod(ll b, ll e, ll m) {
	ll ret = 1;
	while (e) {
		if (e%2) ret = mulmod(ret, b, m);
		b = mulmod(b, b, m);
		e /= 2;
	}
	return ret;
}
bool miller(ll n) {
    if (n < 2) return false;
    for (ll p : {2, 3, 5, 7, 11, 13, 17, 19}) {
        if (n % p == 0) 
            return (n == p);
    }
    if (n < 529) return true; // 23^2 = 529
    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    auto witness = [&](ll a) {
        ll x = expmod(a % n, d, n);
        if (x == 1 || x == n - 1) return false;
        for (int i = 1; i < s; i++) {
            x = mulmod(x, x, n);
            if (x == n - 1) return false;
        }
        return true; // "true" => 'a' es testigo => n es compuesto
    };
    // Bases para 64 bits
    for (ll b : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (b % n == 0) return true; 
        if (witness(b)) return false; 
    }
    return true; // "probable primo"
};
ll rho(ll n) {
	if(n % 2 == 0) return 2;
	ll x = 2, y = 2, d = 1;
	ll c = rand() % n + 1;
	while(d == 1) {
		x = (mulmod(x, x, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		y = (mulmod(y, y, n) + c) % n;
		d = __gcd(x - y, n);
	}
	return d == n ? rho(n) : d;
}
void fact(ll n, map<ll, int>& F) { // Agrega los factores de n en F
	if (n == 1) return;
	if (miller(n)) {F[n]++; return;}
	ll q = rho(n); fact(q, F); fact(n / q, F);
}
