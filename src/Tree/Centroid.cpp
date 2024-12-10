#include <bits/stdc++.h>
using namespace std;

#define L(i, j, n) for (int i = (j); i < int(n); i ++)
#define ii pair<int, int>
const int inf = 1e9;
const int N = 1e5;

vector<int> G[N];
int ct[N];
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
    ct[cen] = p;
    if (p == -1) root = cen;

    if (tree_size == 1) return;

    for (int v: G[cen]){
        if (removed[v]) continue;
        build(v, sz[v], cen);
    }

}

void update(int v){
    int u = v;
    while(v != -1){
        dist[v].insert(distance(u, v), v);
        v = par[v];
    }
    return res;
}

int query(int v){
    int u = v;
    int res = INT_MAX;
    while(v != -1){
        res = min(res, distance(u, v), dist[v].begin()->first); // Minimun
        v = par[v];
    }
    return res;
}