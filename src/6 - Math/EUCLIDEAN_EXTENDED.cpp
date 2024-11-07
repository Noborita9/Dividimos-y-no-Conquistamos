ll extendedGCD(ll a, ll b, ll &x, ll &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

// Función para ajustar x y y según restricciones
bool findSolutionWithConstraints(ll a, ll b, ll c, ll x_min, ll y_min, ll &x, ll &y) {
    ll g = extendedGCD(a, b, x, y);

    // Chequeamos si hay solución
    if (c % g != 0) return false;

    // Escalamos la solución inicial al valor c/g
    x *= c / g;
    y *= c / g;

    // Ajustamos las variables a/g y b/g para mover las soluciones
    a /= g;
    b /= g;

    // Ajuste de x con el mínimo deseado
    if (x < x_min) {
        ll k = (x_min - x + b - 1) / b;  // Redondeo hacia arriba
        x += k * b;
        y -= k * a;
    } else if (x > x_min) {
        ll k = (x - x_min) / b;
        x -= k * b;
        y += k * a;
    }

    // Ajuste de y con el mínimo deseado
    if (y < y_min) {
        ll k = (y_min - y + a - 1) / a;  // Redondeo hacia arriba
        x += k * b;
        y -= k * a;
    } else if (y > y_min) {
        ll k = (y - y_min) / a;
        x -= k * b;
        y += k * a;
    }

    // Verificación final de restricciones
    return x >= x_min && y >= y_min;
}
