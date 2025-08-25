//RECOMENDADO USAR UNSIGNED LONG LONG
static inline ll mulmod(ll a, ll b, ll m) {
    return (ll)((__int128)a * b % m);
}
 
static inline ll powmod(ll b, ll e, ll m) {
    ll r = 1;
    while (e) {
        if (e & 1) r = mulmod(r, b, m);
        b = mulmod(b, b, m);
        e >>= 1;
    }
    return r;
}
 
// RNG rapido
static inline ll splitmix64(ll x) {
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}
static ll rng_state = 0x1234567890abcdefULL ^ chrono::high_resolution_clock::now().time_since_epoch().count();
static inline ll rnd() { return splitmix64(rng_state += 0x9e3779b97f4a7c15ULL); }
 
// trial division pequena para acelerar
static const int SMALL_P_MAX = 1000;
static vector<int> small_primes;
 
static void sieve_small() {
    vector<bool> is(SMALL_P_MAX + 1, true);
    is[0] = is[1] = false;
    for (int i = 2; i * i <= SMALL_P_MAX; ++i) if (is[i])
        for (int j = i * i; j <= SMALL_P_MAX; j += i) is[j] = false;
    for (int i = 2; i <= SMALL_P_MAX; ++i) if (is[i]) small_primes.push_back(i);
}
 
    bool isPrime(ll n) {
    if (n < 2) return false;
    // divide por primos pequenos
    for (int p : small_primes) {
        if ((ll)p * (ll)p > n) break;
        if (n % p == (ll)0) return n == (ll)p;
    }
    if (n < 4) return true; // 2,3
    // Miller-Rabin deterministico para 64-bit
    ll d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, ++s;
    auto witness = [&](ll a) -> bool {
        if (a % n == 0) return false;
        ll x = powmod(a % n, d, n);
        if (x == 1 || x == n - 1) return false;
        for (int i = 1; i < s; ++i) {
            x = mulmod(x, x, n);
            if (x == n - 1) return false;
        }
        return true; // es testigo: n compuesto
    };
    // Bases correctas para 64-bit
    for (ll a : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL,
                 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL}) {
        if (a == 0) continue;
        if (a % n == 0) continue;
        if (witness(a)) return false;
    }
    return true;
}
 
ll pollard_rho(ll n) {
    if ((n & 1ULL) == 0ULL) return 2ULL;
    while (true) {
        ll c = (rnd() % (n - 1)) + 1; // [1..n-1]
        ll x = (rnd() % (n - 2)) + 2; // [2..n-1]
        ll y = x;
        ll d = 1;
        // limite de iteraciones para evitar lazos raros
        for (int it = 0; it < 1'000'000 && d == 1; ++it) {
            x = (mulmod(x, x, n) + c) % n;
            y = (mulmod(y, y, n) + c) % n;
            y = (mulmod(y, y, n) + c) % n;
            ll diff = x > y ? x - y : y - x;
            d = std::gcd(diff, n);
        }
        if (d == 1 || d == n) continue;
        return d;
    }
}
 
void fact(ll n, map<ll,int> &F) {
    if (n == 1) return;
    if (isPrime(n)) { F[n]++; return; }
    for (int p : small_primes) { 
        if ((ll)p * (ll)p > n) break;
        while (n % p == 0) { F[p]++; n /= p; }
    }
    if (n == 1) return;
    if (isPrime(n)) { F[n]++; return; }
    ll d = pollard_rho(n);
    fact(d, F);
    fact(n / d, F);
}
