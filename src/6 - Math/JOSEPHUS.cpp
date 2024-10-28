#include <iostream>
using namespace std;

typedef long long ll;

// Función iterativa para encontrar la posición segura en el problema de Josephus           O (N)
ll josephus_iterative(ll n, ll k) {
    ll result = 0; // Iniciamos con una persona (posición 0 en base 0)
    for (ll i = 2; i <= n; ++i) {
        // Ajustamos la posición segura a medida que aumenta el número de personas
        result = (result + k) % i;
    }
    return result;
}

// Función recursiva para encontrar la posición segura en el problema de Josephus           O (N)
ll josephus_recursive(ll n, ll k) {
    // Caso base: si solo queda una persona, la posición segura es 0 (o la posición 1 en base 1)
    if (n == 1)
        return 0;
    // Llamada recursiva: (josephus(n - 1, k) + k) % n
    return (josephus_recursive(n - 1, k) + k) % n;
}

// Función para encontrar la posición segura cuando k = 2     O (LOG N)
ll josephus_power_of_2(ll n) {
    // Encontrar la mayor potencia de 2 menor o igual a n
    ll power = 1;
    while (power <= n) {
        power <<= 1;
    }
    power >>= 1;
    
    // Usar la fórmula 2 * (n - L), donde L es la mayor potencia de 2 <= n
    return 2 * (n - power);
}