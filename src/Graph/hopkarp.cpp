int L_S, R_S;
vec<int> G[S_MX]; // S_MX (Maxima cantidad de nodos de un lado)
int mat[S_MX];  // matching [0,L_S) -> [0,R_S)
int inv[S_MX];  // matching [0,R_S) -> [0,L_S)

int hopkarp() {
    fill(mat,mat+L_S,-1);
    fill(inv,inv+R_S,-1);
    int size = 0;
    vector<int> d(L_S);
    auto bfs = [&] {
        bool aug = false;
        queue<int> q;
        L(u, 0, L_S) if (mat[u] < 0) q.push(u); else d[u] = -1;
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto v : G[u]) {
                if (inv[v] < 0) aug = true;
                else if (d[inv[v]] < 0) d[inv[v]] = d[u] + 1, q.push(inv[v]);
            }
        }
        return aug;
    };
    auto dfs = [&](auto&& me, int u) -> bool {
        for (auto v : G[u]) if (inv[v] < 0) {
            mat[u] = v, inv[v] = u;
            return true;
        }
        for (auto v : G[u]) if (d[inv[v]] > d[u] && me(me,inv[v])) {
            mat[u] = v, inv[v] = u;
            return true;
        }
        d[u] = 0;
        return false;
    };
    while (bfs()) L(u, 0, L_S) if (mat[u] < 0) size += dfs(dfs,u);
    return size;
}