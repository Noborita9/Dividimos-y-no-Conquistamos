#include <bits/stdc++.h>
using namespace std;
#define TESTS
#define LOCAL

#define ll long long
#define ii pair<ll, ll>
#define F first
#define S second
#define forni(i, o, n) for (int i = o; i < n; i ++)
#define forn(i, n) forni(i, 0, n)
#define pub push_back
#define popf pop_front

#ifdef LOCAL
#define DBG(x) cout << "[" << x << "]";
#else
#define DBG(x) 42
#endif


void solve(){

}


int main(){
    ios::sync_with_stdio(0);cin.tie(0);
#ifdef LOCAL
    freopen("in.txt","r", stdio);
    freopen("out.txt","w", stdout);
#endif
    int tt = 1;
#ifdef TESTS
    cin >> tt;
#endif
    while(tt--)solve();
}
