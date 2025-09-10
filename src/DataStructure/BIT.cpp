#define LSO(S) (S & -S) //LeastsignificantOne
struct FT { // 1-Index
    vec<int> ft; int n;
    FT(vec<int> &v): ft(SZ(v)+1), n(SZ(v)+1) { // O(n)
        L(i, 1, n){ 
            ft[i] += v[i-1];
            if (i + LSO(i) <= n) ft[i + LSO(i)]+=ft[i];
        }
    }
    void update(int pos, int x){ for (int it=pos;it<=n;it+=LSO(it))ft[it]+=x; }
    int sum(int pos){
        int res = 0;
        for (int it=pos;it>0;it-=LSO(it))res+=ft[it];
        return res;
    }
    int getSum(int l, int r){return sum(r) - sum(l - 1);}
};
