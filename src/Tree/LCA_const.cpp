struct LCA {
    vec<int> depth;
    vec<vec<int>> g;
    int K, n;
    vec<vec<int>> st;
    inline int Min(int i, int j) {
        return depth[i] <= depth[j] ? i : j;
    }
    vec<int> in, euler;
    void dfs(int u, int p) {
        in[u] = SZ(euler);
        euler.pb(u);
        for (int v: g[u]) if (v != p){
            depth[v] = depth[u] + 1;
            dfs(v, u);
            euler.pb(u);
        }
    }
    LCA(int n_): depth(n_), g(vec<vec<int>>(n_)), K(0), n(n_), in(n_) {
        euler.reserve(2 * n);
    }
    void add_edge(int u, int v) {
        g[u].pb(v);
    }
    void build(int root){
        dfs(root, -1);
        int ln = SZ(euler);
        while((1<<K)<=ln)K++;
        st = vec<vec<int>> (K, vec<int>(ln));
        L(i,0,ln) st[0][i] = euler[i];
        for (int i = 1; (1 << i) <= ln; i ++) {
            int jmp = (1 << (i - 1));
            for (int j = 0; j + (1<<i) <= ln; j ++) {
                st[i][j] = Min(st[i-1][j], st[i-1][j + jmp]);
            }
        }
    }
    int get(int u, int v) {
        int su = in[u];
        int sv = in[v];
        if (sv < su) swap(sv, su);
        int bit = log2(sv - su + 1);
        return Min(st[bit][su], st[bit][sv - (1<<bit) + 1]);   
    }
};