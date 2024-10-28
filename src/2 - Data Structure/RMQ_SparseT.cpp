int log2_floor(unsigned long long i) {
    return i ? __builtin_clzll(1) - __builtin_clzll(i) : -1;
}

const int MAXN = 10;
int K = log2_floor(MAXN); 
int st[K + 1][MAXN];

// Load Array to st[0][i]
std::copy(array.begin(), array.end(), st[0]);

// Build
for (int i = 1; (1 << i) <= n; i ++){
    for (int j = 0; j + (1 << i) - 1 < n; j ++){
        st[i][j] = min(st[i-1][j], st[i-1][j + (1 << (i - 1))]);
    }
}

// Query
int min_range(int l, int r){
    int C = log2_floor(r - l + 1);
    return min(st[C][l], st[C][r - (1 << C) + 1]);
}
