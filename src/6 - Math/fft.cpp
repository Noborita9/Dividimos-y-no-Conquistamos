#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
typedef long long ll;
const double PI = acos(-1);

void fft(vector<cd> &a, bool invert) {
    ll n = a.size();
    if (n == 1)
        return;
    vector<cd> a0(n / 2), a1(n / 2);
    for (ll i = 0; 2 * i < n; i++) {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }
    fft(a0, invert);
    fft(a1, invert);
    double ang = 2 * PI / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));
    for (ll i = 0; 2 * i < n; i++) {
        a[i] = a0[i] + w * a1[i];
        a[i + n / 2] = a0[i] - w * a1[i];
        if (invert) {
            a[i] /= 2;
            a[i + n / 2] /= 2;
        }
        w *= wn;
    }
}

vector<ll> multiply(vector<ll> const &a, vector<ll> const &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] *= fb[i];
    fft(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}


//Exponensiacion binommial-----------------------------------------

vector<ll> binomial_exponentiation(const vector<ll> &a, int exp) {
    vector<ll> result = {1}; 
    vector<ll> base = a;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = multiply(result, base);
        }
        base = multiply(base, base);
        exp /= 2;
    }

    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }

    return result;
}

//FFT PRECISO --------------------------------------------------------

#define ll long long
using namespace std;
const double pi = acos(-1);

typedef long double ld;
typedef complex<ld> cd;
const ld PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    
    // Permutación bit-reversal
    for (int i = 1, j = 0; i < n; ++i) {
        int bit = n >> 1;
        for (; j & bit; bit >>=1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }

    // Cooley-Tukey FFT
    for (int len = 2; len <= n; len <<=1) {
        ld ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cosl(ang), sinl(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            int len2 = len >> 1;
            for (int j = 0; j < len2; ++j) {
                cd u = a[i + j];
                cd v = a[i + j + len2] * w;
                a[i + j] = u + v;
                a[i + j + len2] = u - v;
                w *= wlen;
            }
        }
    }

    // División por n si es la inversa
    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

vector<ll> multiply(const vector<ll>& a, const vector<ll>& b) {
    const ll BASE = 1e6; // Ajusta BASE según sea necesario

    int n = 1;
    while(n < (int)(a.size() + b.size()))
        n <<= 1;

    vector<cd> al(n), ah(n), bl(n), bh(n);
    for (size_t i = 0; i < a.size(); ++i) {
        al[i] = a[i] % BASE;
        ah[i] = a[i] / BASE;
    }
    for (size_t i = 0; i < b.size(); ++i) {
        bl[i] = b[i] % BASE;
        bh[i] = b[i] / BASE;
    }

    fft(al, false);
    fft(ah, false);
    fft(bl, false);
    fft(bh, false);

    vector<cd> lx(n), lh(n), hl(n), hh(n);
    for (int i = 0; i < n; ++i) {
        lx[i] = al[i] * bl[i];
        lh[i] = al[i] * bh[i];
        hl[i] = ah[i] * bl[i];
        hh[i] = ah[i] * bh[i];
    }

    fft(lx, true);
    fft(lh, true);
    fft(hl, true);
    fft(hh, true);

    vector<ll> result(n);
    for (int i = 0; i < n; ++i) {
        ll temp_ll = llround(lx[i].real());
        ll temp_lh = llround(lh[i].real());
        ll temp_hl = llround(hl[i].real());
        ll temp_hh = llround(hh[i].real());

        result[i] = temp_ll + 
                    ((temp_lh + temp_hl) * BASE) + 
                    (temp_hh * BASE * BASE);
    }

    return result;
}
