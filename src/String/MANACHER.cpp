struct Manacher {
	vec<int> p;
	Manacher(string const& s) {
		int n = SZ(s), m = 2*n+1, l = -1, r = 1;
		vec<char> t(m); L(i, 0, n) t[2*i+1] = s[i];
		p.resize(m); L(i, 1, m) {
			if (i < r) p[i] = min(r-i, p[l+r-i]);
			while (p[i] <= i && i < m-p[i] && t[i-p[i]] == t[i+p[i]]) ++p[i];
			if (i+p[i] > r) l = i-p[i], r = i+p[i];
		}
	} // Retorna palindromos de la forma {comienzo, largo}.
	pii at(int i) const {int k = p[i]-1; return pair{i/2-k/2, k};}
	pii odd(int i) const {return at(2*i+1);} // Mayor centrado en s[i].
	pii even(int i) const {return at(2*i);} // Mayor centrado en s[i-1,i].
};