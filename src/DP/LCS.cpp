string getLCS(string& s1, string& s2) {
    int n = SZ(s1), m = SZ(s2);
    vec<vec<int>> dp(n + 1, vec<int>(m + 1, 0));
    L(i,1,n+1){
        L(j,1,m+1){
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // Reconstruct the LCS
    string lcs;
    int i = n, j = m;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            lcs += s1[i-1];
            i--; j--;
        } else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }
    reverse(ALL(lcs));
    return lcs;
}