vector<int> dfs_num(N, -1), dfs_low(N, -1), visited(N);
int dfs_count = 0;
int numSCC = 0;
stack<int> st;
void dfs(int u){
  dfs_low[u]=dfs_num[u]=dfs_count++;
  st.push(u);
  visited[u] = 1;
  for(int v: G[u]) {
    if (dfs_num[v] == -1) dfs(v);
    if (visited[v]) dfs_low[u] = min(dfs_low[u], dfs_low[v]);
  }
  if (dfs_num[u] == dfs_low[u]){
    numSCC ++;
    while(1){
      int v = st.top(); st.pop();
      visited[v] = 0;
      if (u == v) break;
    }
  }
}
