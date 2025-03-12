ld simpsonRule(function<ld(ld)> f, ld a, ld b, int n) {
    // Asegurarse de que n sea par
    if (n % 2 != 0) {
        n++;
    }
    ld h = (b - a) / n;
    ld s = f(a) + f(b);

    // Suma de terminos interiores con los factores apropiados
    for (int i = 1; i < n; i++) {
        ld x = a + i * h;
        s += (i % 2 == 1 ? 4.0L : 2.0L) * f(x);
    }
    // Multiplica por h/3
    return (h / 3.0L) * s;
}
// Ejemplo: integrar la funcion x^2 entre 0 y 3
auto f = [&](ld x){ return x * x; };
ld a = 0.0L, b = 3.0L;
int n = 1000; // numero de subintervalos
ld resultado = simpsonRule(f, a, b, n);
