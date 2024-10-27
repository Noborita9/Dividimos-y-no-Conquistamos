#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Node structure to store segment information
struct node {
    ll val = 0;    // Change this value based on problem
    ll lazy = 0;   // Change this value based on problem
    
    // Reset the node
    void reset() {
        val = 0;   // Change to appropriate identity value (0, INF, -INF)
        lazy = 0;
    }
    
    // Merge two nodes (change this based on problem)
    void merge(const node& left, const node& right) {
        val = min(left.val, right.val);
        // Other possible operations:
        // val = left.val + right.val;
        // val = max(left.val, right.val);
        // val = gcd(left.val, right.val);
    }
    
    // Apply value to lazy node (change this based on problem)
    void apply(ll x, ll size) {
        val += x;          // For addition
        lazy += x;         // For addition
        
        // For assignment:
        // val = x
        // lazy = x
        
        // For multiplication:
        // val *= x
        // lazy *= x
    }
};

// Actual segment tree implementation
struct Segtree {
    ll n;
    vector<node> tree;
    
    // init tree
    void init(ll _n) {
        n = _n;
        tree.resize(4 * n);
    }
    
    // Reset single node
    void reset(ll id) {
        tree[id].reset();
    }
    
    // Push lazy value down to children
    void push(ll id, ll l, ll r) {
        if (tree[id].lazy == 0) return;  // No lazy value
        
        ll mid = (l + r) >> 1;
        ll left = 2 * id + 1;
        ll right = 2 * id + 2;
        
        // Push to children if not leaf
        if (l != r) {
            tree[left].apply(tree[id].lazy, mid - l + 1);
            tree[right].apply(tree[id].lazy, r - mid);
        }
        
        tree[id].lazy = 0;  // Reset lazy
    }
    
    // Build tree from array
    void build(ll id, ll l, ll r, vector<ll>& arr) {
        if (l == r) {
            tree[id].val = arr[l];
            return;
        }
        ll mid = (l + r) >> 1;
        build(2*id + 1, l, mid, arr);
        build(2*id + 2, mid + 1, r, arr);
        tree[id].merge(tree[2*id + 1], tree[2*id + 2]);
    }
    
    // Update range [ul, ur] with value
    void upd(ll id, ll l, ll r, ll ul, ll ur, ll val) {
        if (l > ur || r < ul) return;
        if (l >= ul && r <= ur) {
            tree[id].apply(val, r - l + 1);
            return;
        }
        push(id, l, r);
        ll mid = (l + r) >> 1;
        upd(2*id + 1, l, mid, ul, ur, val);
        upd(2*id + 2, mid + 1, r, ul, ur, val);
        tree[id].merge(tree[2*id + 1], tree[2*id + 2]);
    }
    
    // Query range [ql, qr]
    node qry(ll id, ll l, ll r, ll ql, ll qr) {
        if (l > qr || r < ql) {
            node res;
            res.reset();
            return res;
        }
        if (l >= ql && r <= qr) return tree[id];
        push(id, l, r);
        ll mid = (l + r) >> 1;
        node left = qry(2*id + 1, l, mid, ql, qr);
        node right = qry(2*id + 2, mid + 1, r, ql, qr);
        node res;
        res.merge(left, right);
        return res;
    }
    
    // Public methods for easier usage
    void build(vector<ll>& arr) { 
        init(arr.size()); 
        build(0, 0, n-1, arr); 
    }
    void upd(ll l, ll r, ll val) { upd(0, 0, n-1, l, r, val); }
    ll qry(ll l, ll r) { return qry(0, 0, n-1, l, r).val; }
};

// Example usage in competitive programming
void solve() {
    ll n, q;
    cin >> n >> q;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];
    
    Segtree sg;
    sg.build(arr);  // Build segment tree
    
    while(q--) {
        ll type, l, r;
        cin >> type >> l >> r;
        if(type == 1) {  // Update query
            ll val; cin >> val;
            sg.upd(l, r, val);
        } else {         // Range query
            cout << sg.qry(l, r) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t = 1;
    // cin >> t;  // Uncomment for multiple test cases
    while(t--) solve();
    
    return 0;
}