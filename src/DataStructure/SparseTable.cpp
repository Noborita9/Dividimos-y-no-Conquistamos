int st[K][1 << K]; int n; vec<int> a(n); // K such (2^K) > n
L(i,0,n)st[0][i]=a[i];
L(k,1,K)L(i,0,n-(1<<k)+1) st[k][i]=min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
auto minlr= [&](int l, int r) -> int {
    int k = 31-__builtin_clz(r - l);
    return min(st[k][l], st[k][r - (1 << k)]);
};
