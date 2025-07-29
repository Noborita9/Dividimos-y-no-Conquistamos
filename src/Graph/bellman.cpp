struct Edge {int a, b, cost;};
vector<Edge> edges;
int solve(int s) // Source
{
    vector<int> d(n, INF);
    d[s] = 0;
    for (int i = 0; i < n - 1; ++i)
        for (Edge e : edges)
            if (d[e.a] < INF)
                d[e.b] = min(d[e.b], d[e.a] + e.cost);
}