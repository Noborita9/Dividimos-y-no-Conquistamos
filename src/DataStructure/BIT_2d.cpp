#define LSO(S) (S & -S)
int f[N][N]; // Initial Matrix
struct BIT {
    vec<vec<int>> B;
    int n;
    BIT(int n_ = 1): B(n_+1,vec<int>(n_+1)), sz(n_) { // N * N * log(N) * log(N);
        for (int i = 1; i <= n_; i ++) 
            for (int j = 1; j <= n_; j ++)
                add(i, j, f[i-1][j-1]);
    }
    void add(int i, int j, int delta){ // log(N) * log(N)
        for (int x = i; x <= n; x += LSO(x))
            for (int y = j; y <= n; y += LSO(y))
                B[x][y] += delta;
    }
    int sum(int i, int j){ // log(N) * log(N)
        int tot = 0;
        for (int x = i; x > 0; x -= LSO(x))
            for(int y = j; y > 0; y -= LSO(y))
                tot += B[x][y];
        return tot;
    }
};