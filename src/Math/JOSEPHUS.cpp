#include <iostream>
using namespace std;

typedef long long ll;

ll josephus_iterative(ll n, ll k) {
    ll result = 0; 
    for (ll i = 2; i <= n; ++i) {
        result = (result + k) % i;
    }
    return result;
}


ll josephus_recursive(ll n, ll k) {

    if (n == 1)
        return 0;

    return (josephus_recursive(n - 1, k) + k) % n;
}


ll josephus_power_of_2(ll n) {

    ll power = 1;
    while (power <= n) {
        power <<= 1;
    }
    power >>= 1;
    

    return 2 * (n - power);
}
