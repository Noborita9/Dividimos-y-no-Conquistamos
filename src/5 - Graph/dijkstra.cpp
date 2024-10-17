
#define ii pair<int, int>

const int N = 10;
const int inf = 1e9;

vector<ii> G[N];

vector<int> dijkstra(int s) {
    vector<int> dist(N, inf);
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0ll, s});
    while(!q.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (d != dist[u]) continue;
        for (ii nei : G[u]){
            int v = nei.second;
            int w = nei.first;
            if (dist[v] > d + w){
                dist[v] = d + w;
                pq.push({dist[v],v});
            }            
        }
    }

    return dist;
}