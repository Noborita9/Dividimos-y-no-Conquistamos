#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

vector<ll> sieve_of_eratosthenes(ll n) {
    
    vector<ll> primes;
    vector<ll> primoRel(n,0);
    for(int i = 2; i < n; i++){
        if(!primoRel[i]){
            primes.push_back(i);
            for(int j = i*i; j < n ;j+=i){
                primoRel[j] = i;
            }
        }
    }
    
    return primes;
}