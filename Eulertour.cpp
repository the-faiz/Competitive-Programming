vector<int> g[100010];
int in[100010];
int out[100010];
int val[100010];
int timer = 0;

void dfs(int node, int par){
    timer++;
    in[node] = timer;
    for(auto v:g[node]){
        if(v!par) dfs(v,node);
    }
    timer++;out[node] = timer;
}

int t[4*2*100010];

void update(int index, int l, int r, int val){} //general update function
int query(int index, int l, int r, int lq, int rq){} //general query function

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    int q;cin>>q;
    while(q--){
        char ch;
        if(ch=='!'){
            int x,y;
            cin>>x>>y;
            update(1,1,2*n,in[x],y);
        }else if(ch=='?'){
            int x;cin>>x;
            query(1,1,2*n,in[x],out[x]);
        }
    }
}