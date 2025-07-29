const int N = 10;

vector<int> G[N];
vector<int> dfs_low(N, -1), dfs_num(N, -1), ap(N, 0); // ap for Articulation Points
int dfs_count = 0;
int root = -1; // For AP

void dfs(int u, int p = -1){
    dfs_low[u]=dfs_num[u]=dfs_count++;
    int child = 0;
    for (int v: G[u]){
        if (v == p) continue;
        if (dfs_num[v] == -1){
            child ++;
            dfs(v, u);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
            if (dfs_low[v] > dfs_num[u]){
              cout << "Bridge " << u << " -> " << v << "\n";
            } 
            if (dfs_low[v] >= dfs_num[u]) {
                ap[u] = 1;
            }
        } else dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
    if (u == root){
        ap[u] = child > 1;
    }
}