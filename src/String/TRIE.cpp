struct Trie {
    map<char, int> ch;
    bool eee;
    Trie(): eee(0) {} 
};
vec<Trie> t;
void initTrie(){t.clear();t.pb(Trie());}
void insert(string &word) {
    int v = 0;
    for(char c : word) {
        if(!t[v].ch[c]) {
            t[v].ch[c] = SZ(t);
            t.pb(Trie());
        }
        v = t[v].ch[c];
    }
    t[v].eee = 1;
}