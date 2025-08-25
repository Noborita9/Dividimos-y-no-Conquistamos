vec<int> g[N];
int L; // L should be (1<<L) > n
int jump[20][N];
int depth[N];

void dfs(int u, int p){
    for (int v: g[u]) if (v != p) {
        jump[0][v] = u;
        L(i, 1, L + 1) {
            jump[i][v] = -1;
            if (jump[i - 1][v] != -1) {
                jump[i][v] = jump[i - 1][jump[i - 1][v]];
            }
        }    
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int LCA(int u, int v){
    if (depth[u] < depth[v]) swap(u, v); // Make u the deepest
    for (int i = L; i >= 0; i --){ // make them same depth
        if (jump[i][u] != -1 && depth[jump[i][u]] >= depth[v]){ 
            u = jump[i][u];
        }
    }
    if (u == v) return u; // u is parent of v
    for (int i = L; i>= 0; i --){
        if (jump[i][u] != jump[i][v] && jump[i][u] != -1 && jump[i][v] != -1){
            u = jump[i][u];
            v = jump[i][v];
        }
    }
    return jump[0][u];
}