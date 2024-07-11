void bellmanford(int sc){
    dis.assign(n+1,inf);
    dis[sc] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x = edge[j].F.F;
            int y = edge[j].F.S;
            int wt = edge[j].S;
            dis[y] = min(dis[y],dis[x]+wt);
        }
    }
}