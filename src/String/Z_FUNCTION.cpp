#include <bits/stdc++.h>

using namespace std;

vector<int> z_function(string s) {
    int n = s.length();
    vector<int> z(n, 0);
    
    z[0] = n;
    
    int l = 0, r = 0;
    
    for(int i = 1; i < n; i++) {
        if(i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        
        if(i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    
    return z;
}


vector<int> find_pattern(string text, string pattern) {

    string s = pattern + "$" + text;
    vector<int> z = z_function(s);
    vector<int> result;
    

    for(int i = pattern.length() + 1; i < s.length(); i++) {
        if(z[i] == pattern.length()) {
            result.push_back(i - pattern.length() - 1);
        }
    }
    
    return result;
}
