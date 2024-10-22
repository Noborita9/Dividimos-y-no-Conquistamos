#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Función para calcular el producto cruzado de tres puntos (P1, P2, P3)
ll cross_product(pair<ll, ll> P1, pair<ll, ll> P2, pair<ll, ll> P3) {
    ll x1 = P2.first - P1.first;
    ll y1 = P2.second - P1.second;
    ll x2 = P3.first - P1.first;
    ll y2 = P3.second - P1.second;
    return x1 * y2 - y1 * x2;
}

// Función para calcular la distancia entre dos puntos
double distancia(pair<ll, ll> P1, pair<ll, ll> P2) {
    return sqrt((P2.first - P1.first) * (P2.first - P1.first) +
                (P2.second - P1.second) * (P2.second - P1.second));
}

// Función para calcular el producto punto de dos vectores (P1->P2) y (P1->P3)
ll dot_product(pair<ll, ll> P1, pair<ll, ll> P2, pair<ll, ll> P3) {
    ll x1 = P2.first - P1.first;
    ll y1 = P2.second - P1.second;
    ll x2 = P3.first - P1.first;
    ll y2 = P3.second - P1.second;
    return x1 * x2 + y1 * y2;
}