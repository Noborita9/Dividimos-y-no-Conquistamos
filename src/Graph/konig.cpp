vec<int> cover[2]; // if cover[i][j] = 1 -> node i, j is part of cover
int konig() {
    cover[0].assign(L_S,true); // L_S left size
    cover[1].assign(R_S,false); // R_S right size
    int size = hopkarp();  // alternativamente, tambien funciona con Kuhn
    auto dfs = [&](auto&& me, int u) -> void {
        cover[0][u] = false;
        for (auto v : g[u]) if (!cover[1][v]) {
            cover[1][v] = true;
            me(me,inv[v]);
        }
    };
    L(u,0,L_S) if (mat[u] < 0) dfs(dfs,u);
    return size;
}