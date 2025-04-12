const int N = 10;
int G[N][N]; // This Graph should be a copy, to de used as dintances
for (int k = 0;k < n; k ++)
    for (int i = 0; i < n; i ++)
        for (int j = 0;j < n; j ++)
            G[i][j] = min(G[i][j], G[i][k] + G[k][j]);