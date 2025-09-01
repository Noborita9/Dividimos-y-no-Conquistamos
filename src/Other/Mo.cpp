const int BLOCK_SIZE = 450; using U64 = uint64_t;
struct query {int l, r, id;U64 order;};
U64 hilbertorder(U64 x, U64 y) {
    const U64 logn = __lg(max(x, y) * 2 + 1) | 1;
    const U64 maxn = (1ull << logn) - 1;
    U64 res = 0;
    for (U64 s = 1ull << (logn - 1); s; s >>= 1) {
        bool rx = x & s, ry = y & s;
        res = (res << 2) | (rx ? ry ? 2 : 1 : ry ? 3 : 0);
        if (!rx) {
            if (ry) x ^= maxn, y ^= maxn;
            swap(x, y);
        }
    }
    return res;
} // sort by this order
auto add = [&](int ix) { /* Add A[ix] to state*/};
auto rem = [&](int ix) { /* Remove A[ix] from state*/}
int c_l = 0, c_r = -1; // Cursors [0,-1] so r add 0 on first q
L(const auto &qr: queries){
    while(c_l > qr.l) add(--c_l);
    while(c_r < qr.r) add(++c_r);
    while(c_l < qr.l) rem(c_l++);
    while (c_r > qr.r) rem(c_r--);
    ans[qr.id] = /*State.Answer()*/;
}