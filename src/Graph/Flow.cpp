// Complexity (V * V * E);
struct Dinic {
    struct Edge {
        int to, rev;
        long long cap, flow;
        Edge(int to, int rev, long long cap) : 
            to(to), rev(rev), cap(cap), flow(0) {}
    };
    
    vector<vector<Edge>> g;
    vector<int> level, ptr;
    queue<int> q;
    int n, source, sink;
    const long long INF = 1e18;
    
    Dinic(int n, int s, int t) : n(n), source(s), sink(t) {
        g.resize(n);
        level.resize(n);
        ptr.resize(n);
    }
    
    void add_edge(int from, int to, long long cap) {
        g[from].emplace_back(to, g[to].size(), cap);
        g[to].emplace_back(from, g[from].size()-1, 0);  // Reverse edge
    }
    
    bool bfs() {
        while(!q.empty()) {
            q.pop();
        }
        fill(level.begin(), level.end(), -1);
        
        q.push(source);
        level[source] = 0;
        
        while(!q.empty() && level[sink] == -1) {
            int v = q.front();
            q.pop();
            
            for(const Edge& e : g[v]) {
                if(level[e.to] == -1 && e.flow < e.cap) {
                    level[e.to] = level[v] + 1;
                    q.push(e.to);
                }
            }
        }
        return level[sink] != -1;
    }
    
    long long dfs(int v, long long pushed) {
        if(v == sink || pushed == 0) return pushed;
        
        for(int& i = ptr[v]; i < (int)g[v].size(); i++) {
            Edge& e = g[v][i];
            
            if(level[e.to] != level[v] + 1 || e.flow >= e.cap) continue;
            
            long long flow = dfs(e.to, min(pushed, e.cap - e.flow));
            if(flow == 0) continue;
            
            e.flow += flow;
            g[e.to][e.rev].flow -= flow;
            return flow;
        }
        return 0;
    }
    
    long long max_flow() {
        long long flow = 0;
        
        while(bfs()) {
            fill(ptr.begin(), ptr.end(), 0);
            while(long long pushed = dfs(source, INF)) {
                flow += pushed;
            }
        }
        return flow;
    }
    
    // Get the actual flow passing through each edge
    vector<vector<long long>> get_flow() {
        vector<vector<long long>> flow(n, vector<long long>(n, 0));
        for(int v = 0; v < n; v++) {
            for(const Edge& e : g[v]) {
                if(e.cap > 0) {  // Only original edges, not residual
                    flow[v][e.to] = e.flow;
                }
            }
        }
        return flow;
    }
    
    // Find minimum cut
    vector<bool> min_cut() {
        vector<bool> reachable(n, false);
        queue<int> q;
        q.push(source);
        reachable[source] = true;
        
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            
            for(const Edge& e : g[v]) {
                if(!reachable[e.to] && e.flow < e.cap) {
                    reachable[e.to] = true;
                    q.push(e.to);
                }
            }
        }
        return reachable;
    }
};

// Example usage:
/*
int main() {
    // Example: 6 vertices, source = 0, sink = 5
    int n = 6;
    Dinic flow(n, 0, 5);
    
    // Add edges: (from, to, capacity)
    flow.add_edge(0, 1, 16);
    flow.add_edge(0, 2, 13);
    flow.add_edge(1, 2, 10);
    flow.add_edge(1, 3, 12);
    flow.add_edge(2, 1, 4);
    flow.add_edge(2, 4, 14);
    flow.add_edge(3, 2, 9);
    flow.add_edge(3, 5, 20);
    flow.add_edge(4, 3, 7);
    flow.add_edge(4, 5, 4);
    
    // Calculate maximum flow
    long long max_flow = flow.max_flow();
    cout << "Maximum flow: " << max_flow << "\n";
    
    // Get minimum cut
    vector<bool> cut = flow.min_cut();
    cout << "Vertices on source side of min cut: ";
    for(int i = 0; i < n; i++) {
        if(cut[i]) cout << i << " ";
    }
    cout << "\n";
    
    // Get flow through each edge
    auto flow_matrix = flow.get_flow();
    cout << "Flow matrix:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(flow_matrix[i][j] > 0) {
                cout << i << " -> " << j << ": " << flow_matrix[i][j] << "\n";
            }
        }
    }
    
    return 0;
}
*/