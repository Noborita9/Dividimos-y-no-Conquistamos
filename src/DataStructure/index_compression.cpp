template<class T>
struct Index{ // If only 1 use Don't need to copy T type
    vec<T> d; int sz;
    Index(const vec<T> &a): d(ALL(a)){
        sort(ALL(d)); // Sort 
        d.erase(unique(ALL(d)), end(d)); // Erase continuous duplicates
        sz = SZ(d); }
    inline int of(T e) const{return lower_bound(ALL(d), e) - begin(d);} // get index
    inline T at(int i) const{return d[i];} // get value of index
};