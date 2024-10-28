//Descompone en primos
vector<pair<ll, ll>> prime_factors(ll n) {
    vector<pair<ll, ll>> factors;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ll count = 0;
            while (n % i == 0) {
                n /= i;
                count++;
            }
            factors.push_back({i, count});
        }
    }
    if (n > 1) factors.push_back({n, 1});
    return factors;
}

// Función para obtener todos los divisores de un número n
vector<ll> divisors(ll n) {
    vector<ll> divs;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i) { // Evita duplicar si n es un cuadrado perfecto
                divs.push_back(n / i);
            }
        }
    }
    sort(divs.begin(), divs.end()); // Ordena los divisores en orden ascendente
    return divs;
}