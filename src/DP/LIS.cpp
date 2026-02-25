int lis(vec<int> &a) {
    int n = SZ(a);
    vector<int> d(n+1, oo);
    d[0] = -oo;
    L(i,0,n){
        int l = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[l-1] < a[i] && a[i] < d[l]) d[l] = a[i];
    }
    int ans = 0;
    for (int l = 0; l <= n; l++) if (d[l] < oo) ans = l;
    return ans;
}