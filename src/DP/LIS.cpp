vector<int> getLIS(vector<int>& arr) {
    int n = arr.size();
    vector<int> dp(n + 1, INT_MAX);  // dp[i] = smallest value that ends an LIS of length i
    vector<int> len(n);              // Length of LIS ending at each position
    dp[0] = INT_MIN;
    
    for(int i = 0; i < n; i++) {
        int j = upper_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        dp[j] = arr[i];
        len[i] = j;
    }
    
    // Find maxLen and reconstruct sequence
    int maxLen = 0;
    for(int i = n-1; i >= 0; i--) maxLen = max(maxLen, len[i]);
    
    vector<int> lis;
    for(int i = n-1, currLen = maxLen; i >= 0; i--) {
        if(len[i] == currLen) {
            lis.push_back(arr[i]);
            currLen--;
        }
    }
    reverse(lis.begin(), lis.end());
    return lis;
}