template<class T>
struct Index{ // If only 1 use Don't need to copy T type
    vec<T> d;
    int sz;
    Index(vec<T> &a): d(ALL(a)){
        sort(ALL(d)); // Sort 
        d.erase(unique(ALL(d)), end(d)); // Erase continuous duplicates
        sz = SZ(d); }
    int of(T e){return lower_bound(ALL(d), e) - begin(d);} // get index
    T at(int i){return d[i];} // get value of index
};