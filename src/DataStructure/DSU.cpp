struct DSU {
    vec<int> par, sz; int n;
    DSU(int n = 1): par(n), sz(n, 1), n(n) {
        L(i,0,n)par[i]=i;
    }
    int find(int a){return a == par[a] ? a : par[a] = find(par[a]);}
    void join(int a, int b){
        a=find(a);b=find(b);
        if (a != b){
            if (sz[b] > sz[a]) swap(a,b);
            par[b] = a;
            sz[a] += sz[b];
        }
    }
};
