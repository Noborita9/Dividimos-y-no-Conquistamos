bool vis[N], r[N];
struct ACvertex {
	map<char,int> next,go;
	int p,link;
	char pch;
	vector<int> leaf;
	ACACvertex(int p=-1, char pch=-1):p(p),pch(pch),link(-1){}
};
vector<ACvertex> t;
void aho_init(){ //do not forget!!
	t.clear();t.pb(ACvertex());
}
void add_string(string s, int id){
	int v=0;
	for(char c:s){
		if(!t[v].next.count(c)){
			t[v].next[c]=t.size();
			t.pb(ACvertex(v,c));
		}
		v=t[v].next[c];
	}
	t[v].leaf.pb(id);
}
int go(int v, char c);
int get_link(int v){ // Failure link
	if(t[v].link<0)
		if(!v||!t[v].p)t[v].link=0;
		else t[v].link=go(get_link(t[v].p),t[v].pch);
	return t[v].link;
}
int go(int v, char c){ // state = go(state, ch) this state is ACvertex id
	if(!t[v].go.count(c))
		if(t[v].next.count(c))t[v].go[c]=t[v].next[c];
		else t[v].go[c]=v==0?0:go(get_link(v),c);
	return t[v].go[c];
}
void proc(int x){
    if (x == - 1|| vis[x]) return;
    vis[x] = 1;
    L(i,0,SZ(t[x].leaf)) r[t[x].leaf[i]] = 1;
    proc(get_link(x));
}