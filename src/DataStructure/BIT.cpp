#define LSOne(S) (S & -S)

struct BIT {
    vector<int> B;
    int n;
    BIT(int n = 1): B(n + 1), n(n+1){}
    BIT(vector<int> &v): B(v.size()+1), n(v.size()+1) {
        for (int i = 1; i <= n; i ++){
            B[i] += v[i-1];
            if (i + LSOne(i) <= n){
                B[i + LSOne(i)] += B[i];
            }
        }
    }
    void update(int i, int x){
        while (i <= n){
            B[i] += x;
            i += LSOne(i);
        }
    }
    int sum(int i){
        int res = 0;
        while (i > 0){
            res += B[i];
            i -= LSOne(i);
        }
        return res;
    }
    int range_sum(int l, int r){
        return sum(r) - sum(l - 1);
    }
};