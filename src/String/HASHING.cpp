static constexpr ll ms[] = {1'000'000'007, 1'000'000'403};
static constexpr ll b = 500'000'000;
struct StrHash { // Hash polinomial con exponentes decrecientes.
	vector<ll> hs[2], bs[2];
	StrHash(string const& s) {
		int n = SZ(s);
		L(k, 0, 2) {
			hs[k].resize(n+1), bs[k].resize(n+1, 1);
			L(i, 1, n) {
				hs[k][i+1] = (hs[k][i] * b + s[i]) % ms[k];
				bs[k][i+1] =  bs[k][i] * b         % ms[k];
			}
		}
	}
	ll get(int idx, int len) const { // Hashes en `s[idx, idx+len)`.
		ll h[2];
		L(k, 0, 2) {
			h[k] = hs[k][idx+len] - hs[k][idx] * bs[k][len] % ms[k];
			if (h[k] < 0) h[k] += ms[k];
		}
		return (h[0] << 32) | h[1];
	}
};

pll union_hash(vector<pll> hs, vector<ll> lens){ //use arrays makes it slower
	ll len = 0;
	for(int i = hs.size()-1; i > 0; i--){
		len += lens[i];
		pll& [l1, l2] = hs[i];
		pll& [r1, r2] = hs[i-1];
		l1 = ((l1 * binpow(b, len, ms[0])) % ms[0] + r1) % ms[0];
		l2 = ((l2 * binpow(b, len, ms[1])) % ms[1] + r2) % ms[1];
	}

	return hs[0];
}