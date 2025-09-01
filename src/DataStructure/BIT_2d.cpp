#define LSO(S) (S & -S)
struct BIT { // 1-Index
    vec<vec<int>> B;
    int n; // BUILD: N * N * log(N) * log(N)
    BIT(int n_ = 1): B(n_+1,vec<int>(n_+1)), sz(n_) {}
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
    int getSum(int x1, int y1, int x2, int y2) {
        return sum(x2, y2) - sum(x2, y1) - sum(x1, y2) + sum(x1-1,y1-1);
    }
};