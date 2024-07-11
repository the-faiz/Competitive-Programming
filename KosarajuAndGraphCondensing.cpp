void dfs1(int node){
    vis[node] = 1;
    for(auto ele:g[node]){
        if(!vis[ele]) dfs1(ele);
    }
    tout_order.push_back(node);
}

int scc_num[100010];
int curr_scc = 0;

void dfs2(int node){
    scc_num[node] = curr_scc;
    vis[node] = 1;
    for(auto v:grev[node]){
        if(!vis[v]) dfs2(v);
    }
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        grev[b].push_back(a);
    }

    vis.clear();vis.assign(n+1,0);
    for(int i=1;i<=n;i++){
        if(!vis[i]) dfs1(i);
    }
    reverse(tout_order.begin(),tout_order.end());
    vis.clear();vis.assign(n+1,0);
    for(auto x:tout_order){
        if(!vis[x]){
            curr_scc++;
            dfs2(x);
        }
    }

    //Forming the condensed graph
    condensed_graph.resize(curr_scc+1);
    for(int i=1;i<=n;i++){
        for(auto v:g[i]){
            if(scc_num[i]!=scc_num[v]){
                condensed_graph[scc_num[i]].push_back(scc_num[v]);
            }
        }
    }
}