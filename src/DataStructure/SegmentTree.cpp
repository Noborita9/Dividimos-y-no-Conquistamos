#define LC(v) (v<<1)
#define RC(v) ((v<<1)|1)
#define MD(L, R) (L+((R-L)>>1))
struct node {
    ll mx;
    ll cant; };
struct ST {
    vec<node> st;
    vec<ll> lz; int n;
    ST(int n = 1): st(4 * n + 10, {oo, oo}), lz(4 * n + 10, 0), n(n) {build(1, 0, n - 1);}
    node merge(node a, node b){
        if (a.mx == oo) return b;
        if (b.mx == oo) return a;
        if (a.mx == b.mx) return {a.mx, a.cant + b.cant};
        return {max(a.mx, b.mx), a.mx > b.mx ? a.cant : b.cant};
    }
    void build(int v, int L, int R){
        if (L == R){
            st[v] = {0, 1};
        } else {
            int m = MD(L, R);
            build(LC(v), L, m);
            build(RC(v), m + 1, R);
            st[v] = merge(st[LC(v)], st[RC(v)]);
        }
    }
    void push(int v, int L, int R){
        if (lz[v]){
            if (L != R){
                st[LC(v)].mx += lz[v];
                st[RC(v)].mx += lz[v];
                lz[LC(v)] += lz[v];
                lz[RC(v)] += lz[v];
            }
            lz[v] = 0;
        }
    }
    void update(int v, int L, int R, int ql, int qr, ll w){
        if (ql > R || qr < L) return;
        push(v, L, R);
        if (ql == L && qr == R){
            st[v].mx += w;
            lz[v] += w;
            push(v, L, R);
            return;
        }
        int m = MD(L, R);
        update(LC(v), L, m, ql, min(qr, m), w);
        update(RC(v), m + 1, R, max(m + 1, ql), qr, w);
        st[v] = merge(st[LC(v)], st[RC(v)]);
    }
    node query(int v, int L, int R, int ql, int qr){
        if (ql > R || qr < L) return {oo, oo};
        push(v, L, R);
        if (ql == L && qr == R) return st[v];
        int m = MD(L, R);
        return merge(query(LC(v), L, m, ql, min(m, qr)), query(RC(v), m + 1, R, max(m + 1, ql), qr));
    }
    node query(int l, int r){return query(1, 0, n - 1, l, r);}
    void update(int l, int r, ll w){update(1, 0, n - 1, l, r, w);}
};