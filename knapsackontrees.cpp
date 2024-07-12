vector<int> g[101];
vector<int> arr[101];
int dp[101][2][101]; //first state = node level, second is whether I can take or not, third is how may are left to take
int sz[101];

void dfs(int node, int par){
    for(int i=0;i<=100;i++){//initializing the dp as node to be a leaf
        dp[node][1][i]=(i==1?arr[node]:-1e9);
        dp[node][0][i]=(i==0?0:-1e9);
    }
    for(auto v:g[node]){
        if(v!=par){
            dfs(v,node);
            sz[node]+=sz[v];

            for(int a=100;a>=0;a--){
                for(int b=100;b>=0;b--){
                    dp[node][0][a+b] = max(dp[node][0][a+b], dp[node][0][a]+max(dp[node][0][b],dp[node][1][b]));
                }
            }
        }
    }
}