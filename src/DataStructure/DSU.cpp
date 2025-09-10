struct DSU {
    vec<int> par, sz; int n;
    DSU(int n = 1): par(n), sz(n, 1), n(n) { iota(ALL(par), 0); }
    int find(int a){return a == par[a] ? a : par[a] = find(par[a]);}
    void join(int a, int b){
        a=find(a);b=find(b);
        if (a == b) return;
        if (sz[b] > sz[a]) swap(a,b);
        par[b] = a; sz[a] += sz[b];
    }
};
