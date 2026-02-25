int LIS(vec<int>& a){
    vec<int> P;
    P.pb(a[0]);
    L(i,1,SZ(a)) {
        if (a[i] > P.back()) P.pb(a[i]);
        else {
            auto ix = upper_bound()

        }
    }
    return SZ(P);
}