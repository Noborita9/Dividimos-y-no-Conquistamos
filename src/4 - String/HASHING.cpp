#include <bits/stdc++.h>
#define ll long long

using namespace std;

// este struct permite crear unordered_set de pares
struct pair_hash {
  inline std::size_t operator()(const std::pair<ll,ll> & v) const {
    return v.first*31+v.second;
  }
};

const int p = 31; //representa la potencia, inicializalo en base a la cantidad de letras que use el alfabeto
const int m = 1e9 + 9; //mod

vector<ll> precompute_pow(ll size){ //el size debe ser el largo del string evaluado
  vector<ll> res(size);
  res[0] = 1;

  for(int i = 1; i < size; i++)
    res[i] = (res[i - 1] * p) % m;

  return res;
}

vector<ll> precompute_hash(string s, vector<ll> pow){
  ll size = s.size();
  vector<ll> hs(size + 1, 0);

  for(int i = 0; i < size; i++)
    hs[i+1] = (hs[i] * ((s[i] - 'a' + 1) * pow[i]) % m) % m;

  return hs;
}

