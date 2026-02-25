// dp[k][i] = min(dp[k-1][j] + cost(j,i)), con j <= i
// requiere monotonicidad: opt[k][i] <= opt[k][i+1]
// uso: definir cost(j,i) y llamar dnc_dp(n, K)
// base 1
auto calc = [&](int j, int l, int r, int optL, int optR, auto&& self) -> void {
    if (l > r) return;
    int m = (l + r) >> 1;
    ll best = oo;
    int opt = optL;
    int hi = min(m, optR);
    L(i, optL, hi + 1) {
        ll v = dp[i - 1][j - 1] + cost[i][m];
        if (v < best) {
            best = v;
            opt = i;
        }
    }
    dp[m][j] = best;
    self(j, l, m - 1, optL, opt, self);
    self(j, m + 1, r, opt, optR, self);
};
L(j, 1, k + 1) {
    calc(j, 1, n, 1, n, calc);
}