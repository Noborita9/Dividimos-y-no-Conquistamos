// Complexity (maxFlow * E);
#define ll long long
const ll INF = (ll)4e18;
struct Edge {
    int from, to;
    ll cap, flow;
    Edge(int from, int to, ll cap) : from(from), to(to), cap(cap), flow(0) {}
};

struct MaxFlow {
    vector<Edge> edges;
    vector<vector<int>> adj;
    vector<int> level, ptr;
    int n;
    queue<int> q;

    MaxFlow(int n) : n(n) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int from, int to, ll cap) {
        edges.emplace_back(from, to, cap);
        edges.emplace_back(to, from, 0);
        adj[from].push_back(edges.size() - 2);
        adj[to].push_back(edges.size() - 1);
    }

    bool bfs(int s, int t) {
        while(!q.empty()) q.pop();
        fill(level.begin(), level.end(), -1);
        
        q.push(s);
        level[s] = 0;
        
        while(!q.empty() && level[t] == -1) {
            int v = q.front();
            q.pop();
            
            for(int id : adj[v]) {
                if(level[edges[id].to] == -1 && edges[id].cap - edges[id].flow > 0) {
                    level[edges[id].to] = level[v] + 1;
                    q.push(edges[id].to);
                }
            }
        }
        return level[t] != -1;
    }

    ll dfs(int v, int t, ll pushed) {
        if(v == t || pushed == 0)
            return pushed;
        
        for(; ptr[v] < (int)adj[v].size(); ptr[v]++) {
            int id = adj[v][ptr[v]];
            int u = edges[id].to;
            
            if(level[u] != level[v] + 1) continue;
            
            ll tr = dfs(u, t, min(pushed, edges[id].cap - edges[id].flow));
            if(tr > 0) {
                edges[id].flow += tr;
                edges[id ^ 1].flow -= tr;
                return tr;
            }
        }
        return 0;
    }

    ll max_flow(int s, int t) {
        ll flow = 0;
        while(bfs(s, t)) {
            fill(ptr.begin(), ptr.end(), 0);
            while(ll pushed = dfs(s, t, LLONG_MAX)) {
                flow += pushed;
            }
        }
        return flow;
    }
    
    // Returns the actual flow through each edge
    vector<ll> get_flows() {
        vector<ll> flows;
        for(int i = 0; i < edges.size(); i += 2) {
            flows.push_back(edges[i].flow);
        }
        return flows;
    }
};