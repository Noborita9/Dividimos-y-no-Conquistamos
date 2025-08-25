struct SPT {
    vec<vec<int>> st;
    int K;
    SPT(vec<int> &a): K(0) {
        int n = SZ(a);
        while((1<<K)<=n) K ++;
        st = vec<vec<int>>(K, vec<int>(n));
        L(i,0,n) st[0][i] = a[i];
        for (int i = 1; (1 << i) <= n; i ++) {
            int jmp = (1 << (i - 1));
            for (int j = 0; j + (1 << i) <= n; j ++) {
                st[i][j] = min(st[i-1][j], st[i - 1][j + jmp]);
            }
        }
    }
    int get(int l, int r) {
        int bit = log2(r - l + 1);
        return min(st[bit][l], st[bit][r - (1<<bit) + 1]);
    }
};