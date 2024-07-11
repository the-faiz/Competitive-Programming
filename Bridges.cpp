void dfs(int node, int par){
    vis[node] = 1;
    tin[node] = lo[node] = timer++;
    int child = 0;
    for(auto ele:g[node]){
        if(ele==par) continue;
        if(vis[ele]==1) lo[node] = min(lo[node],tin[ele]);
        else{
            dfs(ele,node);
            lo[node] = min(lo[node],lo[ele]);
            if(lo[ele]>tin[node]){
                //the edge from node to ele is a critical edge
            }
            child++;
        }
    } 
}

