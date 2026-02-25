bool spfa(int s, vec<int>& d) {
    int n = SZ(g); // needs g graph
    d.assign(n, INF);
    vec<int> cnt(n, 0), inqueue(n, 0);
    queue<int> q; q.push(s);
    d[s] = 0; inqueue[s] = true;
    while (SZ(q)) {
        int u = q.front(); q.pop();
        inqueue[u] = false;
        for (auto [v, w] : g[u]) {
            if (d[u] + w < d[v]) {
                d[v] = d[u] + w;
                if (!inqueue[v]) {
                    q.push(v); inqueue[v] = true;
                    cnt[v]++;
                    if (cnt[v] > n) return false;  // negative cycle
                }
            }
        }
    }
    return true;
}