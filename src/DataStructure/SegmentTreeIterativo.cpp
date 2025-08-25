const ll oo = 1e18;
ll nst;
vec<ll> st;

void build(ll n, vec<ll> &a){
    nst = 1;
    while(nst <= n) nst <<=1;
    st.assign(2*nst,-oo); // Asignar valor base (si fuese minimo poner +oo)
    L(i,0,a.size()) st[nst+i] = a[i];
    for(int i = nst-1; i > 0; i--) st[i] = max(st[i*2],st[i*2+1]); 
}

void upd(ll pos, ll val){
    pos += nst;
    st[pos] = val;
    pos >>=1;
    while(pos > 0){
        st[pos] = max(st[pos*2],st[pos*2+1]);
        pos >>=1;
    }
}

ll query(ll l, ll r){ // no inclusivo query(0,n) = max(st[0], st[1], ... st[n-1])
    ll res = -oo;
    l += nst; r += nst;
    while(l < r){
        if(l & 1) res = max(res,st[l++]);
        if(r & 1) res = max(res,st[--r]);
        l >>= 1; r >>= 1;
    }
    return res;
}
