void pra(int arr[],int n){
  for(int i=0;i<n;i++) cout<<arr[i]<<" ";
  cout<<endl;
}
void prv(vector<int> &v){
  for(int i=0;i<v.size();i++)cout<<v[i]<<" ";
  cout<<endl;
}
int binx(int a,int b,int p){
  if(b==0) return 1;
  if(b%2) return (a%p)*(binx(a,b-1,p)%p)%p;
  else{
    int temp = binx(a,b/2,p)%p;
    return (temp*temp)%p;
  }
}
int invmod(int a,int p){
  return binx(a,p-2,p);
}
