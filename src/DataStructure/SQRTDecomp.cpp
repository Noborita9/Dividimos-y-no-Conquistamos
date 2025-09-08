struct SQRTDecomp {
    vec<int> B, Bs, Bid; int n;// DEFINE BLOCK_SIZE
    SQRTDecomp(int n_): B(n_), Bid(n_), n(n_) { // About sqrt N
        Bs.assign((n + BLOCK_SIZE - 1)/BLOCK_SIZE, 0);
        L(i,1,n) Bid[i] = Bid[i - 1] + (i % BLOCK_SIZE == 0);
    } // useful if many updates not many queries, may be better than st
    void upd(int ix, int w) { B[ix] += w; Bs[Bid[ix]] += w;} // O(1)
    int query(int l, int r){ // O(BLOCK_SIZE)
        int ans = 0;
        for (int i = l; i < r;) {
            if (i + BLOCK_SIZE > r || (i % BLOCK_SIZE) != 0) ans += B[i ++];
            else { ans += Bs[Bid[i]]; i += BLOCK_SIZE;}
        }
        return ans;
    }
};