template<class Char=char>vector<int> zfun(const basic_string<Char>& w) {
	int n = SZ(w), l = 0, r = 0; vector<int> z(n);
  z[0] = w.length();
	L(i, 1, n) {
		if (i <= r) {z[i] = min(r - i + 1, z[i - l]);}
		while (i + z[i] < n && w[z[i]] == w[i + z[i]]) {++z[i];}
		if (i + z[i] - 1 > r) {l = i, r = i + z[i] - 1;}
	}
	return z;
}