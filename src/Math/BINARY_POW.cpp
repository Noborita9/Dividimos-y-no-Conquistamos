#include <iostream>
using namespace std;

typedef long long ll;
ll mod = 1e9+7;

ll binary_pow(ll base, ll exp) {
    ll result = 1;
    base %= mod; 
    while (exp > 0) {
        if (exp % 2 == 1) { 
            result = (result * base) % mod;
        }
        base = (base * base) % mod; 
        exp /= 2; 
    }
    
    return result;
}
