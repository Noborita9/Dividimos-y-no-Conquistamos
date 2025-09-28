vec<int> KMP(const string &s){
    int n = SZ(s); vec<int> pi(n);
    L(i,1,n){
        int j = pi[i - 1];
        while(j>0&&s[i]!=s[j]) j = pi[j-1];
        if (s[i]==s[j])j++;
        pi[i]=j;
    }
    return pi;
}
