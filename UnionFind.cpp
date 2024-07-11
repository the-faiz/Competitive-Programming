struct UnionFind{
  int n,set_size,*parent,*rank;
  UnionFind(){}
  UnionFind(int a){
      n = set_size = a;
      parent = new int[n+1];
      rank = new int[n+1];
      for(int i=1;i <=n; ++i) {parent[i]=i; rank[i]=1;}
  }
  int find(int x){
      if(x!=parent[x]) return parent[x] = find(parent[x]);
      return x;
  }
  void merge(int x, int y){
      int xroot = find(x), yroot = find(y);
      if(xroot!=yroot){
          if(rank[xroot]>=rank[yroot]){
              rank[xroot]+=rank[yroot];
              parent[yroot] = parent[xroot];
          }
          else{
              rank[yroot] += rank[xroot];
              parent[xroot] = yroot;
          }
          set_size-=1;
      }
  }
  void reset(){
      set_size = n;for(int i=1;i<=n;i++) {parent[i]=i;rank[i]=1;}
  }
  int size(){return set_size;}
  void print(){for(int i=1;i<=n;i++) cout<<i<<"->"<<parent[i]<<endl;}
};
