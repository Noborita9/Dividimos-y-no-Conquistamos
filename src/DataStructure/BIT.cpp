#define LSO(S) (S & -S)
struct BIT {
    vec<int> B;
    int n;
    BIT(int n = 1): B(n + 1), n(n+1){}
    BIT(vec<int> &v): B(SZ(v)+1), n(SZ(v)+1) {
        LI(i, 1, n){
            B[i] += v[i-1];
            if (i + LSO(i) <= n){
                B[i + LSO(i)] += B[i];
            }
        }
    }
    void update(int i, int x){
        while (i <= n){
            B[i] += x;
            i += LSO(i);
        }
    }
    int sum(int i){
        int res = 0;
        while (i > 0){
            res += B[i];
            i -= LSO(i);
        }
        return res;
    }
    int range_sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};
