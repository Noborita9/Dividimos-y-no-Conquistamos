struct Node {
    long long sum = 0;
    long long min_val = LLONG_MAX;
    long long max_val = LLONG_MIN;
    long long lazy = 0;
    
    // Merge function to combine two nodes
    void merge(const Node& left, const Node& right) {
        sum = left.sum + right.sum;
        min_val = min(left.min_val, right.min_val);
        max_val = max(left.max_val, right.max_val);
    }
    
    // Update function for lazy propagation
    void apply(int l, int r, long long value) {
        sum += (r - l + 1) * value;
        min_val += value;
        max_val += value;
        lazy += value;
    }
};

struct SegTree {
    int n;
    vector<Node> tree;
    
    SegTree(int n) : n(n) {
        tree.resize(4 * n + 5);
    }
    
    SegTree(vector<int>& arr) : n(arr.size()) {
        tree.resize(4 * n + 5);
        build(arr, 0, 0, n-1);
    }
    
    // Push lazy value to children
    void push(int id, int l, int r) {
        if (tree[id].lazy == 0) return;
        
        int mid = (l + r) >> 1;
        tree[2*id + 1].apply(l, mid, tree[id].lazy);
        tree[2*id + 2].apply(mid+1, r, tree[id].lazy);
        tree[id].lazy = 0;
    }
    
    void build(vector<int>& arr, int id, int l, int r) {
        if (l == r) {
            tree[id].sum = arr[l];
            tree[id].min_val = arr[l];
            tree[id].max_val = arr[l];
            return;
        }
        
        int mid = (l + r) >> 1;
        build(arr, 2*id + 1, l, mid);
        build(arr, 2*id + 2, mid+1, r);
        tree[id].merge(tree[2*id + 1], tree[2*id + 2]);
    }
    
    // Range update with lazy propagation
    void update(int id, int l, int r, int ql, int qr, long long val) {
        if (ql > r || qr < l) return;
        
        if (ql <= l && r <= qr) {
            tree[id].apply(l, r, val);
            return;
        }
        
        push(id, l, r);
        int mid = (l + r) >> 1;
        update(2*id + 1, l, mid, ql, qr, val);
        update(2*id + 2, mid+1, r, ql, qr, val);
        tree[id].merge(tree[2*id + 1], tree[2*id + 2]);
    }
    
    // Range query
    Node query(int id, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return Node();
        
        if (ql <= l && r <= qr) {
            return tree[id];
        }
        
        push(id, l, r);
        int mid = (l + r) >> 1;
        Node left = query(2*id + 1, l, mid, ql, qr);
        Node right = query(2*id + 2, mid+1, r, ql, qr);
        
        Node result;
        result.merge(left, right);
        return result;
    }
    
    // Public interface
    void update(int l, int r, long long val) {
        update(0, 0, n-1, l, r, val);
    }
    
    Node query(int l, int r) {
        return query(0, 0, n-1, l, r);
    }
};