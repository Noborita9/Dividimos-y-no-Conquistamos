vec<vec<ll>> expbinmat(vec<vec<ll>> mat, ll b) {

    ll n = mat.size();

    vec<vec<ll>> resp(n, vec<ll>(n, 0));
    L(i, 0, n) {
        resp[i][i] = 1;
    }
    while (b > 0) {
        if (b % 2 == 1) {
            mult(resp, mat);
        }
        mult(mat, mat);
        b /= 2;

    }
    return resp;
}

// Ejemplo de uso: An = C1*An-1 + C2*An-2 + C3*An-3 
// con A0 = B0, A1 = B1, A2 = B2

if (n == 0) cout << B0 << '\n';
else if (n == 1) cout << B1 << '\n';
else if (n == 2) cout << B2 << '\n';
else {
    vec<vec<ll>> M = {
        {C1, C2, C3},
        {1,  0,  0},
        {0,  1,  0}
    };

    M = expbinmat(M, n - 2);

    ll resp = (B2 * M[0][0] + B1 * M[0][1] + B0 * M[0][2]) % MOD;

    cout << resp << '\n';
}