#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < int(n); i ++)
#define ii pair<int, int>
const int inf = 1e9;
const int N = 1e5;

vector<int> G[N], ct[N];
set<ii> dist[N];
int up[N][18];
int colors[N];
int depth[N];
int sz[N];
bool removed[N];
int n, root, L;

int getSize(int u, int p){
    int szi = 1;
    for(int v: G[u]){
        if (p == v || removed[v]) continue;
        szi += getSize(v, u);
    }
    return sz[u] = szi;
}

int centroid(int u, int tree_size, int p){
    for (int v: G[u]){
        if (v == p || removed[v]) continue;
        if (sz[v] * 2 > tree_size) return centroid(v, tree_size, u);
    }
    return u;
}

void build(int node, int tree_size, int p)
{
    getSize(node, - 1);
    int cen = centroid(node, tree_size, -1);
    removed[cen] = 1;
    if (p != -1){
        ct[cen].push_back(p);
    } else root = cen;

    if (tree_size == 1) return;

    for (int v: G[cen]){
        if (removed[v]) continue;
        build(v, sz[v], cen);
    }

}

void dfs(int u, int p){
    up[u][0] = p;
    for (int i = 1; i <= L; i ++){
        if (up[u][i-1] != -1) up[u][i] = up[up[u][i-1]][i-1];
        else up[u][i] = -1;
    }
    for (int v: G[u]){
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int LCA(int u, int v){
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = L; i >= 0; i --){
        if (up[u][i] != -1 && depth[up[u][i]] >= depth[v]){
            u = up[u][i];
        }
    }
    if (u == v) return u;
    for (int i = L; i>= 0; i --){
        if (up[u][i] != up[v][i] && up[u][i] != -1 && up[v][i] != -1){
            u = up[u][i];
            v = up[v][i];
        }
    }
    return up[u][0];
}

int dis(int u, int v){
    int cmm = LCA(u, v);
    // cout << u << " " << v << " " << cmm << "\n";
    return depth[u] + depth[v] - (2 * depth[cmm]);
}

void uup(int u, int node){
    dist[u].insert({dis(u, node), node});
    for (int v: ct[u])
        uup(v, node);
}

void update(int node){
    dist[node].insert({0, node});
    for (int v: ct[node])
        uup(v, node);
}

int qup(int u, int node){
    int mn = dis(node, u) + dist[u].begin()->first;
    for (int v: ct[u]) mn = min(mn, qup(v, node));
    return mn;
}
    
int query(int node){
    int mn = dist[node].begin()->first;
    for (int v: ct[node]) mn = min(mn, qup(v, node));
    return mn;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int m; cin >> n >> m;
    L = log2(n);
    L(i, 1, n){
        int u, v; cin >> u >> v;
        u --; v --;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    L(i, 0, n){
        dist[i].insert({inf, i});
    }
    build(0, n, -1);
    L(i, 0, L + 1) up[root][i] = -1;
    run(root, -1);
    update(0);
    L(_q, 0, m){
        int op, node; cin >> op >> node;
        if (op == 2){
            cout << query(node-1) << '\n';
        } else {
            update(node-1); // Log Log
        }
    }
}