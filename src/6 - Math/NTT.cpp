#include <bits/stdc++.h>
using namespace std;
using cd = complex<double>;
typedef long long ll;
const ll mod = 998244353;
const ll root = 31;           
const ll root_1 = inverse(root, mod); 
const ll root_pw = 1 << 23;  

ll inverse(ll a, ll m) {
    ll res = 1, exp = m - 2; 
    while (exp) {
        if (exp % 2 == 1) res = (1LL * res * a) % m;
        a = (1LL * a * a) % m;
        exp /= 2;
    }
    return res;
}

void ntt(vector<ll> & a, bool invert) {
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        int wlen = invert ? root_1 : root;
        for (int i = len; i < root_pw; i <<= 1)
            wlen = (int)(1LL * wlen * wlen % mod);

        for (int i = 0; i < n; i += len) {
            int w = 1;
            for (int j = 0; j < len / 2; j++) {
                int u = a[i+j], v = (int)(1LL * a[i+j+len/2] * w % mod);
                a[i+j] = u + v < mod ? u + v : u + v - mod;
                a[i+j+len/2] = u - v >= 0 ? u - v : u - v + mod;
                w = (int)(1LL * w * wlen % mod);
            }
        }
    }

    if (invert) {
        int n_1 = inverse(n, mod);
        for (auto & x : a)
            x = (int)(1LL * x * n_1 % mod);
    }
}

vector<ll> multiply(vector<ll> const &a, vector<ll> const &b) {
    vector<ll> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    ll n = 1;
    while (n < a.size() + b.size()) 
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    ntt(fa, false);
    ntt(fb, false);
    for (ll i = 0; i < n; i++)
        fa[i] = (fa[i] * fb[i]) % mod;
    ntt(fa, true);

    vector<ll> result(n);
    for (ll i = 0; i < n; i++)
        result[i] = fa[i];
    return result;
}