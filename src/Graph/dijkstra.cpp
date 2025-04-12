vector<pll> G[N];
vec<ll> dijk(ll s) { // Need more data, ask vectors by argument
    vec<ll> dist(N, oo);
    dist[s] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    pq.push({0ll, s});
    while(!q.empty()){
        auto [d, u] = pq.top();pq.pop(); 
        if (d != dist[u]) continue;
        for (auto [v, w] : G[u]){
            if (dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v],v});
            }            
        }
    }
    return dist;
}